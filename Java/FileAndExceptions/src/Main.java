import java.io.File;

public class Main {
    public static void main(String[] args) {
        File fl;
        File f1;
        File f2;
        File f3;
        File directory = FileMerge.getDirectoryFromUser();

        do {
            System.out.println("This file needs to not be empty");
            fl = FileMerge.getFileFromUser(directory);
        } while (fl.length() == 0);
        f1 = fl;

        do {
            System.out.println("This file needs to not be empty");
            fl = FileMerge.getFileFromUser(directory);
        } while (fl.length() == 0);
        f2 = fl;

        do {
            System.out.println("This file needs to be empty");
            fl = FileMerge.getFileFromUser(directory);
        } while (fl.length() != 0);
        f3 = fl;

        FileMerge.nOfLines(f1);
    }
}