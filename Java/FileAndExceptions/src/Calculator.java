public class Calculator {
    private int num;
    private double result = 0;


    public Calculator() {
        this.num = 0;
    }

    public Calculator(int num) {
        this.num = num;
    }

    private boolean isInRange(int n) {
        if(n >= -100 && n <= 100) {
            throw new IllegalArgumentException(n + " not in range");
        }
    }

    public void addition(int n) {
        if(isInRange(n)) return;

        this.setNum(n);
        this.result += this.num;
    }

    public void subtraction(int n) {
        if(isInRange(n)) return;

        this.setNum(n);
        this.result -= this.num;
    }

    public void multiplication(int n) {
        if(isInRange(n)) return;

        this.setNum(n);
        this.result *= this.num;
    }

    public void division(int n) {
        if(isInRange(n)) return;

        if(n == 0) {
            throw new ArithmeticException("cant divide by 0");
        } else {
            this.setNum(n);
            this.result /= this.num;
        }
    }

    public void modulo(int n) {
        if(isInRange(n)) return;

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
        if(isInRange(n)) return;

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
