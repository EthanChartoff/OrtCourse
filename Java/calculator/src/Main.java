import java.util.ArrayList;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        // our test arrayList
        ArrayList<ExpressionElement> elements = new ArrayList< >();
// add literals
        elements.add(new Literal(14));
        elements.add(new Literal(0));
        elements.add(new Literal(-4));
        elements.add(new Literal(13.1415));
        elements.add(new Literal(-0.1));
// create subtraction operators
        ExpressionElement sub0 = new OperatorSubtract(elements.get(2),elements.get(2));
        ExpressionElement sub1 = new OperatorSubtract(sub0, elements.get(2));
        ExpressionElement sub2 = new OperatorSubtract(elements.get(0), sub1);
        ExpressionElement sub3 = new OperatorSubtract(elements.get(3), sub1);
        ExpressionElement sub4 = new OperatorSubtract(sub3, elements.get(4));
// add subtraction operators
        elements.add(sub0);
        elements.add(sub1);
        elements.add(sub2);
        elements.add(sub3);
        elements.add(sub4);
// test
        for (ExpressionElement element : elements) // foreach
        {
            System.out.println(element + " = " + element.eval());
        }
    }
}