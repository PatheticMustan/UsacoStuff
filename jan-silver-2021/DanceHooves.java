import java.util.*;

public class DanceHooves {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        
        // oh god, a collection of sets
        // sets, because we want to remove dupes
        // tracks where each cow has visited
        Map<Integer, Set<Integer>> placesVisited = new HashMap<Integer, Set<Integer>>();
        // track cow ID's
        int[] cows = new int[n];
        for (int i=0; i<n; i++) {
            cows[i] = i;
            placesVisited.put(i, new HashSet<Integer>());
            placesVisited.get(i).add(i);
        }

        // store the dance moves for later
        int[][] danceMoves = new int[k][2];
        for (int i=0; i<k; i++) {
            // stupid off by 1 error
            danceMoves[i] = new int[] { sc.nextInt()-1, sc.nextInt()-1};
        }
        
        for (int danceStep=0; danceStep<k; danceStep++) {
            int moveFrom = danceMoves[danceStep][0];
            int moveTo = danceMoves[danceStep][1];

            // swap
            placesVisited.get(cows[moveFrom]).add(moveTo);
            placesVisited.get(cows[moveTo]).add(moveFrom);
            int temp = cows[moveFrom];
            cows[moveFrom] = cows[moveTo];
            cows[moveTo] = temp;
        }

        for (int i=0; i<n; i++) {
            Map<Integer, Set<Integer>> newPlacesVisited = placesVisited;

            for (int o=0; o<n; o++) {
                Set<Integer> placesIter = new HashSet<Integer>(newPlacesVisited.get(o));
                Set<Integer> places = newPlacesVisited.get(o);
                
                for (int cowID : placesIter) {
                    places.addAll(placesVisited.get(cowID));
                }
            }

            placesVisited = newPlacesVisited;
        }

        // System.out.println(placesVisited);

        for (int i=0; i<n; i++) {
            System.out.println(placesVisited.get(i).size());
        }

        sc.close();
    }
}