public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        calc.addition(10);
        calc.subtraction(8);
        calc.multiplication(2);
        // calc.division(0);
        calc.division(2);
        calc.modulo(3);
        calc.subtraction(4);
        calc.pow(3);
//         calc.sqrt();
        calc.setResult(16);
        calc.sqrt();
    }
}