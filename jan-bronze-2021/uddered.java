import java.util.Scanner;

public class uddered {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String alphabet = sc.nextLine();
        String letters = sc.nextLine();

        int last = -1;
        int times = 1;

        for (int i=0; i<letters.length(); i++) {
            int index = alphabet.indexOf(letters.charAt(i));
        
            if (index <= last) {
                times++;
            }

            last = index;
        }

        System.out.println(times);

        sc.close();
    }
}