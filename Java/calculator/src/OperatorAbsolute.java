public class OperatorAbsolute extends UnaryOperator {

    public OperatorAbsolute(ExpressionElement operator) {
        super("abs", operator);
    }

    @Override
    public double operate() {
        return Math.abs(getOperator().eval());
    }
}
