package org.example.xo;

import javafx.scene.image.ImageView;

import java.util.Arrays;

public class Game {

    private final int n;
    private final int layers;
    private Connection playerX;
    private Connection playerO;

    private Tile grid[][];

    private int moveCounter;

    private Status status;

    public Game(int n, int layers, Connection playerX, Connection playerO) {
        this.n = n;
        this.layers = layers;
        this.playerX = playerX;
        this.playerO = playerO;
        this.moveCounter = 0;
        this.grid = new Tile[n][n];

        for (int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = Tile.EMPTY;

        this.status = Status.SEARCHING;
    }

    public void initGame() {
        this.status = Status.ACTIVE;

        String msg = ClientRequest.matchFoundRequest(this).getRequest().toString();

        this.playerX.sendRequest(msg);
        this.playerO.sendRequest(msg);
    }

    public void move(ImageView tile, int i) {

    }

    public int getN() {
        return n;
    }

    public int getLayers() {
        return layers;
    }

    public Connection getPlayerX() {
        return playerX;
    }

    public void setPlayerX(Connection playerX) {
        this.playerX = playerX;
    }

    public Connection getPlayerO() {
        return playerO;
    }

    public void setPlayerO(Connection playerO) {
        this.playerO = playerO;
    }

    public Tile[][] getGrid() {
        return grid;
    }

    public void setGrid(Tile[][] grid) {
        this.grid = grid;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "Game{" +
                "n=" + n +
                ", layers=" + layers +
                ", playerX=" + playerX.toString() +
                ", playerO=" + playerO.toString() +
                ", grid=" + Arrays.deepToString(grid) +
                ", moveCounter=" + moveCounter +
                ", status=" + status +
                '}';
    }
}
