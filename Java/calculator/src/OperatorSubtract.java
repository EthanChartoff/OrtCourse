public class OperatorSubtract extends BinaryOperator {
    public OperatorSubtract(ExpressionElement leftExpression, ExpressionElement rightExpression) {
        super("-", leftExpression, rightExpression);
    }

    @Override
    public double operate() {
        return getLeftExpression().eval() - getRightExpression().eval();
    }
}
