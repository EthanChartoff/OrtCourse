package org.example.xo;

import java.io.Serializable;
import java.util.Objects;

public abstract class Request implements Serializable {
    public abstract boolean equals(Object o);

    public abstract String toString();

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
