package part_2;

public class Worker extends Employee {
    private int baseSalary;
    private int workingHours;


    @Override
    float salary() {
        return baseSalary * workingHours;
    }
}
