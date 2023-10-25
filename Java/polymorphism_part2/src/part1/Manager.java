package part1;

public class Manager extends Employee {
    private int monthlySalary;

    public Manager(int monthlySalary) {
        this.monthlySalary = monthlySalary;
    }


    @Override
    float salary() {
        return monthlySalary;
    }
}
