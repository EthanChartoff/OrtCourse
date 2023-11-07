import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        StepIterator stepIterator = new StepIterator(
                3,
                list
        );
        stepIterator.print();
    }
}