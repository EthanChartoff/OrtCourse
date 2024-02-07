package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;

public class Client implements Runnable {

    private Socket socket;

    private final ObjectInputStream inStream;
    private final ObjectOutputStream outStream;

    private final CGame gameController;

    public Client(CGame gameController) {
        try {
            this.socket = new Socket(Server.HOST, Server.PORT);
            this.outStream = new ObjectOutputStream(this.socket.getOutputStream());
            this.inStream = new ObjectInputStream(this.socket.getInputStream());
            this.gameController = gameController;
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            System.out.println("[CLIENT " + this.socket.toString() + "] Connected to server!");
        }
    }

    @Override
    public void run() {
        Object read;
        try {
            while((read = inStream.readObject()) != null)
                this.handleRequest(read);
        } catch (SocketException e) {
            e.printStackTrace();
            System.out.println("[CLIENT " + this.socket.toString() + "] closed connection");
            this.stop();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            System.out.println("on run");
        }
    }

    private void handleRequest(Object read) throws IOException, ClassNotFoundException {
        processRequest(new ClientRequest(read));
    }

    private void processRequest(ClientRequest request) {
        String reqStr = request.getRequest().toString();
        System.out.println("[CLIENT] received: " + request);

        if(ClientRequest.isFoundRequest(request)) {


            Platform.runLater(() -> gameController.initGame());
        }
    }

    public void stop() {
        try {
            this.sendRequest("closing conn " + this.socket.toString());
            this.outStream.flush();
            this.outStream.close();
            this.inStream.close();
            this.socket.close();
            Platform.exit();
            System.exit(0);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void sendRequest(String msg) {
        try {
            outStream.writeObject(msg);
            outStream.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        System.out.println("[CLIENT] new msg: " + msg);
    }

    public String getClientAddress() {
        return this.socket.getInetAddress().toString();
    }

    public void move(Players player, int i) {
        this.sendRequest(ClientRequest.moveRequest(player, i).toString());
    }
}
