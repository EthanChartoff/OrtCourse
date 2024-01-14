package org.example.xo;

import java.io.Serializable;
import java.util.Objects;

public class Request implements Serializable {
    private final Object request;

    public Request(Object request) {
        this.request = request;
    }

    public Object getRequest() {
        return request;
    }

    @Override
    public String toString() {
        return "Request[" +
                "request=" + request +
                ']';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Request request1 = (Request) o;
        return Objects.equals(request, request1.request);
    }

    @Override
    public int hashCode() {
        return Objects.hash(request);
    }
}
