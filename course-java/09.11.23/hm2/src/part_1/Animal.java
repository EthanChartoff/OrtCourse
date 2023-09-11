package part_1;

public abstract class Animal {
    private String color;
    private String name;
    private int age;


    public Animal(String name) {
        this.color = "black";
        this.name = name;
        this.age = 3;
    }

    public Animal(String name, int age) {
        this.color = "black";
        this.name = name;
        this.age = age;
    }

    public Animal(String color, String name, int age) {
        this.color = color;
        this.name = name;
        this.age = age;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "part_1.Animal{" +
                "color='" + color + '\'' +
                ", name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
