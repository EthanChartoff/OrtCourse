package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.Socket;
import java.util.Objects;


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
        Object read;
        try {
            while((read = inputStream.readObject()) != null) {
                this.processRequest(read);
            }
        } catch (EOFException e) {
            System.out.println("[CONNECTION] closing conn: " + this.socket.toString());
            this.close();
        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
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

    private void processRequest(Object request) {
        System.out.println("[CONNECTION] received from client: " + (Request) request);

        if(request instanceof SearchingMatchRequest) {
            searchingForMatch((SearchingMatchRequest) request);
        } else if(request instanceof MoveRequest) {
            clientMoved((MoveRequest) request);
        } else {
            throw new IllegalStateException("Unexpected request type: " + request.getClass());
        }

        Server.requests.put(request.hashCode(), (Request) request);
    }

    private void clientMoved(MoveRequest request) {
        Game currGame = Server.games.get(request.getGameHash());
        Players type = request.getType();


        currGame.setMoveCounter(currGame.getMoveCounter() + 1);
        currGame.setTile(
                request.getIndex() % 3,
                request.getIndex() / 3,
                type == Players.PLAYER_X ? Tile.X : Tile.O
        );

        if(type == Players.PLAYER_X) {
            currGame.getPlayerO().sendRequest(request);
        } else {
            currGame.getPlayerX().sendRequest(request);
        }

        // win situation
        if(checkIfPlayerWon(
                currGame.getGrid(),
                request.getIndex() % currGame.getN(),
                request.getIndex() / currGame.getN(),
                currGame.getN(),
                currGame.getTile(request.getIndex() % currGame.getN(), request.getIndex() / currGame.getN())
        )) {
            currGame.setStatus(Status.INACTIVE);
            currGame.getPlayerX().sendRequest(new GameFinishedRequest(
                    type == Players.PLAYER_X ? PlayerResult.WIN : PlayerResult.LOSS));
            currGame.getPlayerO().sendRequest(new GameFinishedRequest(
                    type == Players.PLAYER_O ? PlayerResult.WIN : PlayerResult.LOSS));
            currGame.setResult(type == Players.PLAYER_X ? GameResult.X : GameResult.O);

            Server.addGameToDB(currGame);
        }
        // draw situation
        else if(currGame.getMoveCounter() >= 9) {
            currGame.setStatus(Status.INACTIVE);
            currGame.getPlayerX().sendRequest(new GameFinishedRequest(
                    PlayerResult.DRAW));
            currGame.getPlayerO().sendRequest(new GameFinishedRequest(
                    PlayerResult.DRAW));
            currGame.setResult(GameResult.DRAW);

            Server.addGameToDB(currGame);
        }
    }

    private boolean checkIfPlayerWon(Tile[][] grid, int x, int y, int n, Tile tile) {
        boolean row = true, col = true, diag = x == y, anti_diag = (x + y) == (n - 1);

        for(int i = 0; i < n; i++) {
            if(row && grid[i][x] != tile)
                row = false;
            if(col && grid[y][i] != tile)
                col = false;
            if(diag && grid[i][i] != tile)
                diag = false;
            if(anti_diag && grid[i][(n-1)-i] != tile)
                anti_diag = false;
        }
        return row || col || diag || anti_diag;
    }

    private void searchingForMatch(SearchingMatchRequest request) {
        try {
            int n = request.getN();
            int layers = request.getLayers();
            boolean gameFound = false;

            for(Game g : Server.games.values()) {
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

            if(!gameFound) {
                Game g = new Game(
                        n,
                        layers,
                        this,
                        null
                );
                Server.games.put(g.hashCode(), g);
            }

        } catch (NumberFormatException e) {
            e.printStackTrace();
        }
    }

    private void foundMatch(Game g) {
        g.setPlayerO(this);
        g.initGame();
    }

    public void sendRequest(Object request) {
        try {
            outputStream.writeObject(request);
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
