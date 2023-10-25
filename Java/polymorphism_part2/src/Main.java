import part1.*;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        ArrayList<Employee> employees = new ArrayList<>();

        employees.add(new Manager(100));
        employees.add(new Sales(5));
        employees.add(new SeniorManager(1000, 5));
        employees.add(new Worker(5, 5));

        employees.forEach(employee -> {
            float salary = employee.salary();
            if(employee.getBirthday())

        });
    }
}