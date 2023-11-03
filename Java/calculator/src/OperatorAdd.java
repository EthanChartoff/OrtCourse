public class OperatorAdd extends BinaryOperator {

    public OperatorAdd(ExpressionElement leftExpression, ExpressionElement rightExpression) {
        super("+", leftExpression, rightExpression);
    }

    @Override
    public double operate() {
        return getLeftExpression().eval() + getRightExpression().eval();
    }
}
