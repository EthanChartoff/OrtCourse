public class SavingAccount {
    static double annualInterestRate = 6;

    private double savingBalance;


    public SavingAccount(double savingBalance) {
        this.savingBalance = savingBalance;
    }

    public static double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public static void setAnnualInterestRate(double annualInterestRate) {
        SavingAccount.annualInterestRate = annualInterestRate;
    }

    public double getSavingBalance() {
        return savingBalance;
    }

    public void setSavingBalance(double savingBalance) {
        this.savingBalance = savingBalance;
    }

    // calc saving balance after a month including interest.
    public void CalculateMonthlyInterest() {
        double monthlyInterest = this.annualInterestRate / 12;
        this.savingBalance += this.savingBalance * (monthlyInterest/100);
    }


    @Override
    public String toString() {
        return "SavingAccount{" +
                "savingBalance=" + savingBalance +
                '}';
    }
}