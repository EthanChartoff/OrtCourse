package part_2;

public class Manager extends Employee {
    private int monthlySalary;


    @Override
    float salary() {
        return monthlySalary;
    }
}
