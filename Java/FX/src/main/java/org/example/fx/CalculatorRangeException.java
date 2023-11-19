package org.example.fx;

public class CalculatorRangeException extends Exception {
    private final int max;
    private final int min;

    public CalculatorRangeException(int max, int min) {
        this.max = max;
        this.min = min;
    }

    public CalculatorRangeException(String message, int max, int min) {
        super(message);
        this.max = max;
        this.min = min;
    }

    public void isInRange(int n) throws CalculatorRangeException {
        if(!(n >= min && n <= max)) {
            throw new CalculatorRangeException(
                    n + " is not in the defined number range",
                    max,
                    min
            );
        }
    }
}
