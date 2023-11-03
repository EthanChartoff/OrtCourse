public class Literal implements ExpressionElement {
    private final double val;


    public Literal(double val) {
        this.val = val;
    }

    @Override
    public double eval() {
        return val;
    }

    @Override
    public String toString() {
        return val >= 0 ? String.valueOf(val) : '(' + String.valueOf(val) + ')';
    }
}
