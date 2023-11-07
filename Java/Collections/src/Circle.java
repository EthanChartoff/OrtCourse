import java.util.Objects;

public class Circle {
    private int rad;

    public Circle(int rad) {
        this.rad = rad;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }

    @Override
    public int hashCode() {
        return Objects.hash(rad);
    }

    public int getRad() {
        return rad;
    }

    public void setRad(int rad) {
        this.rad = rad;
    }
}
