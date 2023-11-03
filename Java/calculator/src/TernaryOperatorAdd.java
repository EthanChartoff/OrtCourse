public class TernaryOperatorAdd extends TernaryOperator {

    public TernaryOperatorAdd(ExpressionElement expression1, ExpressionElement expression2, ExpressionElement expression3) {
        super("+3", expression1, expression2, expression3);
    }

    @Override
    public double operate() {
        return getExpression1().eval() + getExpression2().eval() + getExpression3().eval();
    }
}
