package part_2;

public class Sales extends Employee {
    final private static float salarySalesPercentage = 0.15f;

    private int totalSales;


    @Override
    float salary() {
        return totalSales*salarySalesPercentage;
    }
}
