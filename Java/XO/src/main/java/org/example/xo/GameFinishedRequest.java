package org.example.xo;

import java.util.Objects;

public class GameFinishedRequest extends ClientRequest {
    PlayerResult result;

    public GameFinishedRequest(PlayerResult result) {
        this.result = result;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        GameFinishedRequest that = (GameFinishedRequest) o;
        return result == that.result;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), result);
    }

    @Override
    public String toString() {
        return "GameFinishedRequest{" +
                "result=" + result +
                '}';
    }
}
