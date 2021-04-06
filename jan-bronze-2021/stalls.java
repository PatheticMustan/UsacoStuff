import java.util.*;

public class stalls {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // parsing input
        int n = sc.nextInt();

        long[] a = new long[n];
        for (int i=0; i<n; i++) a[i] = sc.nextLong();

        long[] b = new long[n];
        for (int i=0; i<n; i++) b[i] = sc.nextLong();

        // more vars
        long[] diffs = new long[n];
        for (int i=0; i<n; i++) {
            long sum = 0;
            for (int o=0; o<n; o++) {
                if (a[i] <= b[o]) sum++;
            }

            diffs[i] = sum;
        }
        Arrays.sort(diffs);

        // calc
        long res = 1;
        for (int i=0; i<diffs.length; i++) {
            res *= Math.max(diffs[i] - i, 0);
        }
        
        // output
        //System.out.println(Arrays.toString(diffs));
        System.out.println(res);

        sc.close();
    }
}