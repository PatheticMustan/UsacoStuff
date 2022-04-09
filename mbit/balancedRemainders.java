import java.util.*;

public class balancedRemainders {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        
        for (int e=0; e<t; e++) {
            int n = sc.nextInt();
            int[] a = new int[3];

            for (int i=0; i<n; i++) {
                a[sc.nextInt() % 3]++;
            }

            System.out.println(Arrays.toString(a));
        }



        sc.close();
    }
}