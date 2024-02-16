package org.example.xo;

import java.util.Objects;

public class SearchingMatchRequest extends ServerRequest {
    private final int n;
    private final int layers;

    public SearchingMatchRequest(int n, int layers) {
        this.n = n;
        this.layers = layers;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        SearchingMatchRequest that = (SearchingMatchRequest) o;
        return n == that.n && layers == that.layers;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), n, layers);
    }

    public int getN() {
        return n;
    }

    public int getLayers() {
        return layers;
    }

    @Override
    public String toString() {
        return "SearchingMatchRequest{" +
                "n=" + n +
                ", layers=" + layers +
                '}';
    }
}
