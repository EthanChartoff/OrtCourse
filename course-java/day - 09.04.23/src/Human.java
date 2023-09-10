public class Human {
    private String firstName;
    private String secondName;
    private String idNum;
    private String address;
    private String phoneNum;


    public Human(String firstName, String secondName, String idNum, String address, String phoneNum) {
        this.firstName = firstName;
        this.secondName = secondName;
        this.idNum = idNum;
        this.address = address;
        this.phoneNum = phoneNum;
    }


    @Override
    public String toString() {
        return "Human{" +
                "firstName='" + firstName + '\'' +
                ", secondName='" + secondName + '\'' +
                ", idNum='" + idNum + '\'' +
                ", address='" + address + '\'' +
                ", phoneNum='" + phoneNum + '\'' +
                '}';
    }
}
