package org.example.DB;

import org.example.xo.Game;
import org.example.xo.GameResult;
import org.example.xo.Status;
import org.example.xo.Tile;

public class GameModel extends BaseEntity {
    private int boardSize;
    private int boardLayers;

    private Tile tile00;
    private Tile tile01;
    private Tile tile02;
    private Tile tile10;
    private Tile tile11;
    private Tile tile12;
    private Tile tile20;
    private Tile tile21;
    private Tile tile22;

    private int moveCounter;
    private Status status;
    private GameResult result;

    public GameModel() {}

    public GameModel(Game game) {
        this.boardSize = game.getN();
        this.boardLayers = game.getLayers();
        this.tile00 = game.getTile(0, 0);
        this.tile01 = game.getTile(0, 1);
        this.tile02 = game.getTile(0, 2);
        this.tile10 = game.getTile(1, 0);
        this.tile11 = game.getTile(1, 1);
        this.tile12 = game.getTile(1, 2);
        this.tile20 = game.getTile(2, 0);
        this.tile21 = game.getTile(2, 1);
        this.tile22 = game.getTile(2, 2);
        this.moveCounter = game.getMoveCounter();
        this.status = game.getStatus();
        this.result = game.getResult();
    }

    public int getBoardSize() {
        return boardSize;
    }

    public void setBoardSize(int boardSize) {
        this.boardSize = boardSize;
    }

    public int getBoardLayers() {
        return boardLayers;
    }

    public void setBoardLayers(int boardLayers) {
        this.boardLayers = boardLayers;
    }

    public Tile getTile00() {
        return tile00;
    }

    public void setTile00(Tile tile00) {
        this.tile00 = tile00;
    }

    public Tile getTile01() {
        return tile01;
    }

    public void setTile01(Tile tile01) {
        this.tile01 = tile01;
    }

    public Tile getTile02() {
        return tile02;
    }

    public void setTile02(Tile tile02) {
        this.tile02 = tile02;
    }

    public Tile getTile10() {
        return tile10;
    }

    public void setTile10(Tile tile10) {
        this.tile10 = tile10;
    }

    public Tile getTile11() {
        return tile11;
    }

    public void setTile11(Tile tile11) {
        this.tile11 = tile11;
    }

    public Tile getTile12() {
        return tile12;
    }

    public void setTile12(Tile tile12) {
        this.tile12 = tile12;
    }

    public Tile getTile20() {
        return tile20;
    }

    public void setTile20(Tile tile20) {
        this.tile20 = tile20;
    }

    public Tile getTile21() {
        return tile21;
    }

    public void setTile21(Tile tile21) {
        this.tile21 = tile21;
    }

    public Tile getTile22() {
        return tile22;
    }

    public void setTile22(Tile tile22) {
        this.tile22 = tile22;
    }

    public int getMoveCounter() {
        return moveCounter;
    }

    public void setMoveCounter(int moveCounter) {
        this.moveCounter = moveCounter;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public GameResult getResult() {
        return result;
    }

    public void setResult(GameResult result) {
        this.result = result;
    }
}
