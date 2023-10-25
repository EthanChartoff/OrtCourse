package part1;

public class Sales extends Employee {
    final private static float salarySalesPercentage = 0.15f;

    private int totalSales;

    public Sales(int totalSales) {
        this.totalSales = totalSales;
    }


    @Override
    float salary() {
        return totalSales*salarySalesPercentage;
    }
}
