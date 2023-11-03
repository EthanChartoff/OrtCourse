public class OperatorDivide extends BinaryOperator {

    public OperatorDivide(ExpressionElement leftExpression, ExpressionElement rightExpression) {
        super("/", leftExpression, rightExpression);
    }

    @Override
    public double operate() {
        return getLeftExpression().eval() / getRightExpression().eval();
    }
}
