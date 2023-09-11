package part_2;

public class SeniorManager extends Manager {
    private int bonus;


    @Override
    float salary() {
        return super.salary() + bonus;
    }
}
