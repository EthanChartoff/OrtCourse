package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;

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
            System.out.println(this.getGames());
            Game g = Server.games.get(reqStr.charAt(reqStr.indexOf("index=") + "index=".length()) - '0');
            Platform.runLater(() -> gameController.initGame(g));
        }
    }

    private ArrayList<Game> getGames() {
        try {
            this.sendRequest("need games");
            return ClientRequest.readGames(new ClientRequest(inStream.readObject()));
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
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
