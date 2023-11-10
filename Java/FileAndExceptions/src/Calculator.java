import org.apache.commons.lang3.IntegerRange;

public class Calculator {
    private static final IntegerRange defaultRange = IntegerRange.of(-100, 100);
    private static final CalculatorRangeException defaultRangeException = new CalculatorRangeException(defaultRange);

    private final CalculatorRangeException calculatorRangeException;
    private final IntegerRange range;

    private int num;
    private double result = 0;


    public Calculator() {
        this.calculatorRangeException = defaultRangeException;
        this.range = defaultRange;
        this.num = 0;
    }

    public Calculator(CalculatorRangeException calculatorRangeException, IntegerRange range, int num) {
        this.calculatorRangeException = calculatorRangeException;
        this.range = range;
        this.num = num;
    }

    private void isInRange(int n) {
//        if(n >= -100 && n <= 100) {
//            return true;
//        }
//        throw new IllegalArgumentException(n + " not in range");
        try {
            this.calculatorRangeException.isInRange(n);
        } catch (CalculatorRangeException e) {
            throw new RuntimeException(e);
        }
    }

    public void addition(int n) {
        isInRange(n);

        this.setNum(n);
        this.result += this.num;
    }

    public void subtraction(int n) {
        isInRange(n);

        this.setNum(n);
        this.result -= this.num;
    }

    public void multiplication(int n) {
        isInRange(n);

        this.setNum(n);
        this.result *= this.num;
    }

    public void division(int n) {
        isInRange(n);

        if(n == 0) {
            throw new ArithmeticException("cant divide by 0");
        } else {
            this.setNum(n);
            this.result /= this.num;
        }
    }

    public void modulo(int n) {
        isInRange(n);

        if(this.result == 0) {
            throw new ArithmeticException("cant modulo by 0");
        } else {
            this.setNum(n);
            this.result %= this.num;
        }
    }

    public void sqrt() {
        if(this.result < 0) {
            throw new ArithmeticException("cant sqrt result below 0");
        } else {
            this.result = Math.sqrt(this.result);
        }
    }
    public void pow(int n) {
        isInRange(n);

        this.setNum(n);
        this.result = Math.pow(this.result, this.num);
    }

    public void factorial() {
        if(this.result < 0) {
            throw new ArithmeticException("cant factorial a number below 0");
        } else if(this.result >= 17) {
            throw new IllegalArgumentException("program wont factorial numbers above 16");
        } else {
            int temp = 1;
            for (int i = (int) result; i > 0 ; --i) {
                temp *= i;
            }
            result = temp;
        }
    }

    public int hexToDec(String hex) {
        assert isHex(hex) : "String given is not a hexadecimal";
        return Integer.parseInt(hex, 16);
    }

    public boolean isHex(String hex) {
        for (char c : hex.toCharArray()) {
            if(!((c >= '0' && c <= '9')
                    || (Character.toUpperCase(c) >= 'A' && Character.toUpperCase(c) <= 'F'))) {
                return false;
            }
        }
        return true;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public double getResult() {
        return result;
    }

    public void setResult(double result) {
        this.result = result;
    }
}
