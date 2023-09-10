import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        SavingAccount saver1 = new SavingAccount(5000);
        SavingAccount saver2 = new SavingAccount(6000);
//
//        saver1.CalculateMonthlyInterest();
//        saver2.CalculateMonthlyInterest();
//
//        System.out.println(
//                "saver1 balance " + saver1.getSavingBalance() + "\n" + "saver2 balance " + saver2.getSavingBalance());


        Saver.savers.add(new Saver(
                "ll",
                "k",
                "123",
                "f 1",
                "042",
                new SavingAccount[] {
                        saver1,
                        saver2
                },
                "william"
        ));
//        System.out.println(saver);

        Banker.bankers.add(new Banker(
                "lol",
                "k",
                "123",
                "f 1",
                "042",
                Saver.savers
        ));
        Banker.bankers.add(new Banker(
                "l",
                "k",
                "123",
                "f 1",
                "042",
                Saver.savers
        ));
        Saver falseSaver = new Saver(
                "lol",
                "k",
                "123",
                "f 1",
                "042",
                new SavingAccount[] {
                        saver1,
                        saver2
                },
                "william"
        );
        Banker falseBanker = new Banker(
                "l",
                "k",
                "123",
                "f 1",
                "042",
                Saver.savers
        );

        System.out.println(Banker.customersOfBanker(falseBanker));
        Banker.bankers.add(falseBanker);
        System.out.println(Banker.customersOfBanker(falseBanker));
    }
}