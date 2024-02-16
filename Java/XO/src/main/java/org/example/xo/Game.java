package org.example.xo;

import javafx.scene.image.ImageView;

import java.util.Arrays;

public class Game {

    private final int n;
    private final int layers;
    private Connection playerX;
    private Connection playerO;

    private Tile[][] grid;

    private int moveCounter;

    private Status status;

    private GameResult result;

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
        this.result = GameResult.NULL;
    }

    public void initGame() {
        this.status = Status.ACTIVE;
        System.out.println(this.hashCode());
        MatchFoundRequest msgx = new MatchFoundRequest(n, layers, Players.PLAYER_X, this.hashCode());
        MatchFoundRequest msgo = new MatchFoundRequest(n, layers, Players.PLAYER_O, this.hashCode());

        this.playerX.sendRequest(msgx);
        this.playerO.sendRequest(msgo);
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

    public Tile getTile(int x, int y) {
        return grid[y][x];
    }

    public void setTile(int x ,int y, Tile tile) {
        this.grid[y][x] = tile;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public int getMoveCounter() {
        return moveCounter;
    }

    public void setMoveCounter(int moveCounter) {
        this.moveCounter = moveCounter;
    }

    public GameResult getResult() {
        return result;
    }

    public void setResult(GameResult result) {
        this.result = result;
    }

    @Override
    public String toString() {
        return "Game{" +
                "n=" + n +
                ", layers=" + layers +
                ", playerX=" + playerX +
                ", playerO=" + playerO +
                ", grid=" + Arrays.deepToString(grid) +
                ", moveCounter=" + moveCounter +
                ", status=" + status +
                ", result=" + result +
                '}';
    }
}
