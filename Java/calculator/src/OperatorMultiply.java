public class OperatorMultiply extends BinaryOperator {
    public OperatorMultiply(ExpressionElement leftExpression, ExpressionElement rightExpression) {
        super("*", leftExpression, rightExpression);
    }

    @Override
    public double operate() {
        return getLeftExpression().eval() * getRightExpression().eval();
    }
}
