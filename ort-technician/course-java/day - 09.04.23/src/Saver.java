import java.util.ArrayList;


public class Saver extends Human {

    static ArrayList<Saver> savers = new ArrayList<>();
    final private SavingAccount[] savingAccounts;
    final private String bankerName;
    final private Human humanAttrs;

    public Saver(String firstName, String secondName, String idNum, String address, String phoneNum, SavingAccount[] savingAccounts, String bankerName) {
        super(firstName, secondName, idNum, address, phoneNum);
        this.savingAccounts = savingAccounts;
        this.bankerName = bankerName;
        this.humanAttrs = new Human(
                firstName, secondName, idNum, address, phoneNum
        );
    }


    @Override
    public String toString() {
        return "Saver{" +
                humanAttrs.toString() +
                ", bankerName='" + bankerName + '\'' +
                ", Saving accounts and balances='" + accountsAndBalances() + '\'' +
                ", Number of Accounts='" + savingAccounts.length +
                '}';
    }

    public String accountsAndBalances() {
        String output = "";
        for(int i = 0; i < savingAccounts.length; i++) {
            output += "saving account number " + i + ": " + savingAccounts[i].toString();
            if(i + 1 != savingAccounts.length) {
                output += ", ";
            }
        }
        return output;
    }

    public static String allSaversString() {
        String output = "";

        for(int i = 0; i < savers.size(); i++){
            output += savers.get(i).toString() + '\n';
        }

        return output;
    }

    public static String savingsOfSaver(Saver saver) {
        int saverIndex = Saver.savers.contains(saver) ? Saver.savers.indexOf(saver) : -1;

        if(saverIndex == -1) return "no such saver exists";
        return Saver.savers.get(saverIndex).accountsAndBalances();

    }
}
