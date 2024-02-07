package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.Socket;


public class Connection implements Closeable, Runnable {
    private Socket socket;

    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;


    public Connection(Socket socket) throws IOException {
        this.socket = socket;
        this.inputStream = new ObjectInputStream(socket.getInputStream());
        this.outputStream = new ObjectOutputStream(socket.getOutputStream());
    }

    @Override
    public void run() {
        while(true) {
            try {
                this.handleRequest();
            } catch (EOFException e) {
                System.out.println("[CONNECTION] closing conn: " + this.socket.toString());
                this.close();
            } catch (ClassNotFoundException | IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    @Override
    public void close() {
        try {
            outputStream.close();
            inputStream.close();
            socket.close();
            Platform.exit();
            System.exit(0);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void handleRequest() throws IOException, ClassNotFoundException {
        processRequest(getRequest());
    }

    private ServerRequest getRequest() throws IOException, ClassNotFoundException {
        return new ServerRequest(inputStream.readObject());
    }

    private void processRequest(ServerRequest request) {
        System.out.println("[CONNECTION] received from client: " + request);
        Server.requests.put(request.hashCode(), request);

        if(ServerRequest.isSearchingRequest(request)) {
            this.searchingForMatch(request.getRequest().toString());
        } else if(ServerRequest.isNeedGames(request)) {
            this.sendRequest(Server.games.toString());
        }
    }

    private void searchingForMatch(String request) {
        try {
            int n = request.charAt(request.indexOf("n=") + "n=".length()) - '0';
            int layers = request.charAt(request.indexOf("layers=") + "layers=".length()) - '0';
            boolean gameFound = false;

            for(Game g : Server.games) {
                // if theres a match that searching for another player with the same request
                if(g.getN() == n && g.getLayers() == layers && g.getStatus() == Status.SEARCHING) {
                    gameFound = true;
                    this.foundMatch(g);

                    System.out.println(
                                    "[CONNECTION] game found between "
                                    + g.getPlayerX().getSocket().toString()
                                    + "and " + g.getPlayerO().getSocket().toString());
                    break;
                }
            }

            if(!gameFound)
                Server.games.add(new Game(
                        n,
                        layers,
                        this,
                        null
                ));
        } catch (NumberFormatException e) {
            e.printStackTrace();
        }
    }

    private void foundMatch(Game g) {
        g.setPlayerO(this);
        g.initGame();
    }

    public void sendRequest(String msg) {
        try {
            outputStream.writeObject(msg);
            outputStream.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public Socket getSocket() {
        return socket;
    }

    @Override
    public String toString() {
        return "Connection{" +
                "socket=" + socket +
                ", inputStream=" + inputStream +
                ", outputStream=" + outputStream +
                '}';
    }
}
