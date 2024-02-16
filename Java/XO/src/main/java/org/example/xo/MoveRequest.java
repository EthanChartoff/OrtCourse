package org.example.xo;

public class MoveRequest extends Request {
    private final int gameHash;
    private final Players type;
    private final int index;

    public MoveRequest(int gameHash, Players type, int index) {
        this.gameHash = gameHash;
        this.type = type;
        this.index = index;
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        MoveRequest that = (MoveRequest) o;
        return gameHash == that.gameHash && index == that.index && type == that.type;
    }

    public int getGameHash() {
        return gameHash;
    }

    @Override
    public String toString() {
        return "MoveRequest{" +
                "gameHash=" + gameHash +
                ", type=" + type +
                ", index=" + index +
                '}';
    }

    public Players getType() {
        return type;
    }

    public int getIndex() {
        return index;
    }
}
