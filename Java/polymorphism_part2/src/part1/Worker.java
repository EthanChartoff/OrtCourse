package part1;

public class Worker extends Employee {
    private int baseSalary;
    private int workingHours;

    public Worker(int baseSalary, int workingHours) {
        this.baseSalary = baseSalary;
        this.workingHours = workingHours;
    }


    @Override
    float salary() {
        return baseSalary * workingHours;
    }
}
