import java.util.*;

public class yearOfTheCow {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // input
        int n = sc.nextInt();
        int k = sc.nextInt() - 1;

        double[] input = new double[n];
        for (int i=0; i<n; i++) input[i] = ((double)sc.nextInt())/12;

        // handle edgecase where input is a multiple of 12, with no inbetweens
        Set<Integer> unique = new HashSet<Integer>(); 
        for (double v : input) {
            if (Math.ceil(v) == v) {
                unique.add((int)v);
            } else {
                unique.add((int)Math.ceil(v));
                unique.add((int)Math.floor(v)); 
            }
        }
        // the starting point is a point, as well
        unique.add(0);

        // I hate java so much
        Object[] uniqueArrObj = unique.toArray();
        int[] uniqueArr = new int[uniqueArrObj.length];
        // typecast the object array from Object to int
        // this is why we can't have nice things, java is holding society back from progressing any further
        for (int i=0; i<uniqueArrObj.length; i++) {
            uniqueArr[i] = (int)uniqueArrObj[i];
        }

        // sort in descending order
        // I swear next time I'll just use python, this is too much
        // we want to get the oldest period, since we'll always need to teleport there
        Arrays.sort(uniqueArr);
        int l = uniqueArr.length;

        int[] descending = new int[l];
        for (int i=0; i<l; i++) {
            descending[i] = uniqueArr[l-i-1];
        }

        // find diffs between the periods
        int[] diff = new int[l-1];
        for (int i=0; i<l-1; i++) {
            diff[i] = descending[i] - descending[i+1];
        }
        
        int sum = diff[0];
        // ha, I laugh in the face of unnecessary array copies! Ha, I say! Two ha's! Haha!
        diff = Arrays.copyOfRange(diff, 1, diff.length);

        // sort again, we're going to remove the k-1 biggest differences
        Arrays.sort(diff);
        diff = Arrays.copyOfRange(diff, 0, diff.length-k);

        // finally, sum up the remaining periods
        for (int waitP : diff) {
            sum += waitP;
        }

        System.out.println(sum * 12);

        sc.close();
    }
}