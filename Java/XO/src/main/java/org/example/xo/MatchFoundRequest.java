package org.example.xo;

import java.util.Objects;

public class MatchFoundRequest extends ClientRequest {
    private final int n;
    private final int layers;
    private final Players type;
    private final int gameHash;

    public MatchFoundRequest(int n, int layers, Players type, int gameHash) {
        this.n = n;
        this.layers = layers;
        this.type = type;
        this.gameHash = gameHash;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        MatchFoundRequest that = (MatchFoundRequest) o;
        return n == that.n && layers == that.layers && gameHash == that.gameHash && type == that.type;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), n, layers, type, gameHash);
    }

    public int getGameHash() {
        return gameHash;
    }

    public Players getType() {
        return type;
    }

    @Override
    public String toString() {
        return "MatchFoundRequest{" +
                "n=" + n +
                ", layers=" + layers +
                ", type=" + type +
                ", gameHash=" + gameHash +
                '}';
    }
}
