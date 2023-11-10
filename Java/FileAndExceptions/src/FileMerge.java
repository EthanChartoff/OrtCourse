import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class FileMerge {
    static private Scanner scanner = new Scanner(System.in);

    public static File getDirectoryFromUser() {
        System.out.print("Enter directory path: ");
        File dir = new File(scanner.nextLine());
        while (!dir.exists() || !dir.isDirectory()) {
            System.out.println();
            System.err.print("directory does not exist");
            System.out.print("Enter directory path: ");
            dir = new File(scanner.nextLine());
        }
        return dir;
    }

    public static File getFileFromUser(File directory) {
        System.out.print("Enter file name that is in the dir: ");
        File fl = new File(directory.getPath() + '/' + scanner.nextLine());

        while (!fl.exists() || fl.isDirectory()) {
            System.out.println();
            System.err.println("File does not exist: " + fl.getName());
            System.out.print("Enter file name that is in the dir");
            fl = new File(scanner.nextLine());
        }
        return fl;
    }

    public static void merge(File f1, File f2, File f3) {
        try(
                FileInputStream in1 = new FileInputStream(f1);
                FileInputStream in2 = new FileInputStream(f2);
                FileOutputStream out = new FileOutputStream(f3);
        ) {
            out.write(in1.readAllBytes());
            out.write(in2.readAllBytes());
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static int nOfLines(File fl) {
        int counter = 0;
        try(Scanner scn = new Scanner(fl)) {
            while(scanner.hasNextLine())
                counter++;
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        return counter;
    }

    public static int nOfWords(File fl) {
        int counter = 0;

        try(Scanner scn = new Scanner(fl)) {
            while(scanner.hasNext()) {
                for(String w : scanner.nextLine().split("\\s+")) {
                    counter++;
                }
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        return counter;
    }

    public static int nOfDigits(File fl) {
        int counter = 0;

        try(FileInputStream in = new FileInputStream(fl)) {
            for(char ch : new String(in.readAllBytes(), StandardCharsets.UTF_8).toCharArray()) {
                if(Character.isDigit(ch)) {
                    counter++;
                }
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return counter;
    }

    public static int nOfLetters(File fl) {
        int counter = 0;

        try(FileInputStream in = new FileInputStream(fl)) {
            for(char ch : new String(in.readAllBytes(), StandardCharsets.UTF_8).toCharArray()) {
                if(Character.isLetter(ch)) {
                    counter++;
                }
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return counter;
    }
}
