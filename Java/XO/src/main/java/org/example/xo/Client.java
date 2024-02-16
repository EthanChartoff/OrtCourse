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
                this.processRequest(read);
        } catch (SocketException e) {
            e.printStackTrace();
            System.out.println("[CLIENT " + this.socket.toString() + "] closed connection");
            this.stop();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void processRequest(Object request) {
        System.out.println("[CLIENT] received: " + request.toString());

        if(request instanceof MatchFoundRequest) {
            gameController.setType(((MatchFoundRequest) request).getType());
            Platform.runLater(() -> gameController.initGame(((MatchFoundRequest) request).getGameHash()));
        } else if(request instanceof MoveRequest) {
            gameController.opponentMove((MoveRequest) request);
        } else if(request instanceof GameFinishedRequest) {
            Platform.runLater(() -> new CFinish(gameController.getRoot()).initFinish(
                    ((GameFinishedRequest) request).result));
        }
        else {
            throw new IllegalStateException("Unexpected request type: " + request.getClass());
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

    public void sendRequest(Object request) {
        try {
            outStream.writeObject(request);
            outStream.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        System.out.println("[CLIENT] new msg: " + request);
    }

    public String getClientAddress() {
        return this.socket.getInetAddress().toString();
    }

    public void move(Players type, int i, int gHash) {
        this.sendRequest(new MoveRequest(gHash, type, i));
    }
}
