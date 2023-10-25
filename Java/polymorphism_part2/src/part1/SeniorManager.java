package part1;

public class SeniorManager extends Manager {
    private int bonus;

    public SeniorManager(int monthlySalary, int bonus) {
        super(monthlySalary);
        this.bonus = bonus;
    }

    @Override
    float salary() {
        return super.salary() + bonus;
    }
}
