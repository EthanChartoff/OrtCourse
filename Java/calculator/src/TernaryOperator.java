public abstract class TernaryOperator extends Operator {
    private ExpressionElement expression1;
    private ExpressionElement expression2;
    private ExpressionElement expression3;

    public TernaryOperator(String representation, ExpressionElement expression1, ExpressionElement expression2, ExpressionElement expression3) {
        super(representation);
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.expression3 = expression3;
    }

    @Override
    public String toString() {
        return super.toString() + '(' + expression1 + ", " + expression2 + ", " + expression3 + ')';
    }

    public ExpressionElement getExpression1() {
        return expression1;
    }

    public ExpressionElement getExpression2() {
        return expression2;
    }

    public ExpressionElement getExpression3() {
        return expression3;
    }
}
