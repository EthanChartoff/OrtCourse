public abstract class BinaryOperator extends Operator {
    private ExpressionElement leftExpression;
    private ExpressionElement rightExpression;

    public BinaryOperator(String representation, ExpressionElement leftExpression, ExpressionElement rightExpression) {
        super(representation);
        this.leftExpression = leftExpression;
        this.rightExpression = rightExpression;
    }


    public ExpressionElement getLeftExpression() {
        return leftExpression;
    }

    public ExpressionElement getRightExpression() {
        return rightExpression;
    }

    @Override
    public String toString() {
        return leftExpression + super.toString() + rightExpression;
    }
}
