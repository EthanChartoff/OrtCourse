public class OperatorPower extends BinaryOperator {

    public OperatorPower(ExpressionElement leftExpression, ExpressionElement rightExpression) {
        super("^", leftExpression, rightExpression);
    }

    @Override
    public double operate() {
        return Math.pow(getLeftExpression().eval(), getRightExpression().eval());
    }
}
