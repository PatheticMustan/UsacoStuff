import java.util.*;

public class odd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int groups = 0;
        int odds = 0;
        int evens = 0;

        // 0, 1, 0, 1
        boolean ff = true;

        for (int i=0; i<n; i++) {
            int o = sc.nextInt() % 2;
            if (o == 1) odds++;
            else evens++;
        }

        /*
         * even
         * if (even >= 1) even--
         * elseif (odd >= 2) odd -= 2
         * else break
         * 
         * odd
         * if (odd >= 1) odd--
         * 
         * excess
         * ignore evens
         * odd % 2 == 0, ignore
         * odd % 2 == 1, groups--
         */

        while (true) {
            // even
            if (ff) {
                if (evens >= 1) evens--;
                else if (odds >= 2) odds -= 2;
                else break;
            } else {
                if (odds >= 1) odds--;
                else break;
            }

            ff = !ff;
            groups++;
        }

        if (odds % 2 == 1) groups--;

        System.out.println(groups);

        sc.close();
    }
}