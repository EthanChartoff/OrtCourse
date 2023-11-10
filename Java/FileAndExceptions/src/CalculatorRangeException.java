import org.apache.commons.lang3.IntegerRange;

public class CalculatorRangeException extends Exception {
    private final IntegerRange range;

    public CalculatorRangeException(IntegerRange range){
        this.range = range;
    }

    public CalculatorRangeException(String message, IntegerRange range) {
        super(message);
        this.range = range;
    }

    public void isInRange(int n) throws CalculatorRangeException {
        if(!range.contains(n)) {
            throw new CalculatorRangeException(
                    n + " is not in the defined number range",
                    this.range
            );
        }
    }
}
