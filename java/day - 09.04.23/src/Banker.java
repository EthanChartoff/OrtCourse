import java.util.ArrayList;
import java.util.Arrays;


public class Banker extends Human {

    static ArrayList<Banker> bankers = new ArrayList<>();

    final private ArrayList<Saver> customers;
    final private Human humanAttrs;

    public Banker(String firstName, String secondName, String idNum, String address, String phoneNum, ArrayList<Saver> customers) {
        super(firstName, secondName, idNum, address, phoneNum);
        this.customers = customers;
        this.humanAttrs = new Human(
                firstName, secondName, idNum, address, phoneNum
        );
    }


    @Override
    public String toString() {
        return "Banker{" +
                humanAttrs.toString() +
                ", customers=" + customers.toString() +
                '}';
    }

    public static String allBankersString() {
        String output = "";

        for(int i = 0; i < bankers.size(); i++){
            output += bankers.get(i).toString() + '\n';
        }

        return output;
    }

    public static String customersOfBanker(Banker banker) {
        int bankerIndex = Banker.bankers.contains(banker) ? Banker.bankers.indexOf(banker) : -1;

        if(bankerIndex == -1) return "no such banker exists";
        return Banker.bankers.get(bankerIndex).customers.toString();
    }
}
