package part_1;

public class Cow extends Animal {
    static int cowunter;
    private float liter_of_milk;


    public Cow() {
        super("cow_x");
        liter_of_milk = 20f;
        cowunter++;
    }

    public Cow(String color, String name, int age) {
        super(color, name, age);
        this.liter_of_milk = 20f;
        cowunter++;
    }

    public Cow(String name, int age, float liter_of_milk) {
        super(name, age);
        this.liter_of_milk = liter_of_milk;
        cowunter++;
    }

    public Cow(String color, String name, int age, float liter_of_milk) {
        super(color, name, age);
        this.liter_of_milk = liter_of_milk;
        cowunter++;
    }

    public static int getCowunter() {
        return cowunter;
    }

    public static void setCowunter(int cowunter) {
        Cow.cowunter = cowunter;
    }

    public float getLiter_of_milk() {
        return liter_of_milk;
    }

    public void setLiter_of_milk(float liter_of_milk) {
        this.liter_of_milk = liter_of_milk;
    }

    @Override
    public String toString() {
        return "part_1.Cow{" +
                super.toString() + '\'' +
                "liter_of_milk=" + liter_of_milk +
                '}';
    }
}
