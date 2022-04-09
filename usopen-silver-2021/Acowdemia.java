import java.util.*;

public class Acowdemia {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // get input
        int n = sc.nextInt();
        int K = sc.nextInt();
        int L = sc.nextInt();
        
        // citations
        int[] c = new int[n];
        for (int i=0; i<n; i++) {
            c[i] = sc.nextInt();
        }
        Arrays.sort(c);
        // reverse the stupid array, java is stupid
        // why can't we just have .reverse()
        for(int i = 0; i < c.length / 2; i++) {
            int temp = c[i];
            c[i] = c[c.length-i-1];
            c[c.length-i-1] = temp;
        }

        // surveys
        int[] s = new int[K];
        for (int i=0; i<K; i++) {
            s[i] = L;
        }

        // find max-h, assumes ideal L
        // not actually necessary, but should shave off some time
        int max_h = 1;
        for (int i=0; i<n; i++) {
            if (c[i] + K > i) max_h = i+1;
            else break;
        }

        // you are not valid >:3
        // loop through all citations
        int h = 0;
        int currentSurvey = 0;

        for (; h<max_h; h++) {
            for (int i=0; i<h; i++) {
                System.out.println("AHHH");
                // if it needs to be filled in...
                while (c[i] < h) {
                    System.out.println(h + Arrays.toString(s) + Arrays.toString((c)));
                    // death
                    if (s[currentSurvey] == 0) {
                        System.out.println(h);
                        return;
                    }
                    s[currentSurvey]--;
                    currentSurvey = (currentSurvey + 1) % s.length;
                    c[i]++;
                    
                }
            }
        }

        // never will be called, but just in case
        //System.out.println(h);

        sc.close();
    }
}