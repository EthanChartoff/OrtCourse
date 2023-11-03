public abstract class Operator implements ExpressionElement {
    private final String representation;

    public Operator(String representation) {
        this.representation = representation;
    }

    public abstract double operate();

    @Override
    public double eval() {
        return operate();
    }

    @Override
    public String toString() {
        return representation;
    }
}
