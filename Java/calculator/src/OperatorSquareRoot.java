public class OperatorSquareRoot extends UnaryOperator {

    public OperatorSquareRoot(ExpressionElement operator) {
        super("sqrt", operator);
    }

    @Override
    public double operate() {
        return Math.sqrt(getOperator().eval());
    }
}
