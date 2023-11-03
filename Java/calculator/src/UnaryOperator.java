public abstract class UnaryOperator extends Operator {
    private ExpressionElement expression;

    public UnaryOperator(String representation, ExpressionElement operator) {
        super(representation);
        this.expression = operator;
    }

    public ExpressionElement getOperator() {
        return expression;
    }

    @Override
    public String toString() {
        return super.toString() + expression;
    }
}
