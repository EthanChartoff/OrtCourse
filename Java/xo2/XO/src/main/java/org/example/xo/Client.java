package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;

public class Client implements Runnable {

    private Socket socket;

    private ObjectInputStream inStream;
    private ObjectOutputStream outStream;

    private CGame gameController;

    public Client(CGame gameController) {
        try {
            this.socket = new Socket(Server.HOST, Server.PORT);
            this.outStream = new ObjectOutputStream(this.socket.getOutputStream());
            this.inStream = new ObjectInputStream(this.socket.getInputStream());
            this.gameController = gameController;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void run() {
        Object read;
        try {
            while((read = inStream.readObject()) != null) {
                this.handleRequest(read);
            }
        } catch (SocketException e) {
//            e.printStackTrace();
            System.out.println("[CLIENT " + this.socket.toString() + "] closed connection");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            this.stop();
        }
    }

    private void handleRequest(Object read) throws IOException, ClassNotFoundException {
        processRequest(new ClientRequest(read));
    }

    private void processRequest(ClientRequest request) {
        String reqStr = request.getRequest().toString();
        Game g = Server.getGames().get(reqStr.charAt(reqStr.indexOf("index=") + "index=".length()) - '0');

        System.out.println("[CLIENT] received: " + request);
        if(ClientRequest.isFoundRequest(request)) {
            gameController.initGame(g);
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
        System.out.println("[CLIENT " + this.socket.toString() + "] new msg: " + msg);
    }

    public String getClientAddress() {
        return this.socket.getInetAddress().toString();
    }
}
