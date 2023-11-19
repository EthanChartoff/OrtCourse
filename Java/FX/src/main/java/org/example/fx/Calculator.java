package org.example.fx;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleIntegerProperty;


public class Calculator {
    private static final CalculatorRangeException defaultRangeException = new CalculatorRangeException(100, -100);

    private final CalculatorRangeException calculatorRangeException;

    private IntegerProperty num;
    private DoubleProperty result;


    public Calculator() {
        this.calculatorRangeException = defaultRangeException;
        this.num = new SimpleIntegerProperty();
        this.result = new SimpleDoubleProperty();
        this.num.setValue(0);
        this.result.setValue(0);
    }

    public Calculator(CalculatorRangeException calculatorRangeException, int num, double result) {
        this.calculatorRangeException = calculatorRangeException;
        this.num = new SimpleIntegerProperty();
        this.result = new SimpleDoubleProperty();
        this.num.setValue(num);
        this.result.setValue(result);
    }

    private void isInRange() {
        try {
            this.calculatorRangeException.isInRange(this.num.get());
        } catch (CalculatorRangeException e) {
            throw new RuntimeException(e);
        }
    }

    public void addition() {
        isInRange();

//        this.setNum(n);
        this.result.set(this.result.doubleValue() + this.num.intValue());
    }

    public void subtraction() {
        isInRange();

//        this.setNum(n);
        this.result.set(this.result.doubleValue() - this.num.intValue());
    }

    public void multiplication() {
        isInRange();

//        this.setNum(n);
        this.result.set(this.result.doubleValue() * this.num.intValue());
    }

    public void division() {
        isInRange();

        if(this.num.intValue() == 0) {
            throw new ArithmeticException("cant divide by 0");
        } else {
//            this.setNum(n);
            this.result.set(this.result.doubleValue() / this.num.intValue());
        }
    }

    public void modulo(int n) {
        isInRange();

        if(this.result.doubleValue() == 0) {
            throw new ArithmeticException("cant modulo by 0");
        } else {
//            this.setNum(n);
            this.result.set(this.result.doubleValue() % this.num.intValue());
        }
    }

    public void sqrt() {
        if(this.result.doubleValue() < 0) {
            throw new ArithmeticException("cant sqrt result below 0");
        } else {
            this.result.set(Math.sqrt(this.result.doubleValue()));
        }
    }
    public void pow(int n) {
        isInRange();

//        this.setNum(n);
        this.result.set(Math.pow(this.result.doubleValue(), this.num.intValue()));
    }

    public void factorial() {
        if(this.result.doubleValue() < 0) {
            throw new ArithmeticException("cant factorial a number below 0");
        } else if(this.result.doubleValue() >= 17) {
            throw new IllegalArgumentException("program wont factorial numbers above 16");
        } else {
            int temp = 1;
            for (int i = this.result.intValue(); i > 0 ; --i) {
                temp *= i;
            }
            this.result.set(temp);
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
        return num.get();
    }

    public void setNum(int num) {
        this.num.set(num);
    }

    public IntegerProperty numProperty() {
        return num;
    }

    public double getResult() {
        return result.get();
    }

    public void setResult(double result) {
        this.result.set(result);
    }

    public DoubleProperty resultProperty() {
        return result;
    }
}
