#include <bits/stdc++.h>
using namespace std;



int main() {
    // layout will be locked after n runs, only shifting the left column
    // get input
    int n, q;
    cin >> n >> q;

    int a[n], b[n];
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    int g[q];
    map<int, string> results;
    for (int i=0; i<q; i++) {
        cin >> g[i];
        results[g[i]] = "";
    }


    // solve
    int ao = 0; // a offset so we don't have to constantly re-assign
    // do n runs
    for (int run=0; run<n; run++) {
        // every single court, sort lowest and greatest into a and b
        for (int i=0; i<n; i++) {
            // i + array offset
            int iao = (i+ao)%n;
            int lower = min(a[iao], b[i]),
                higher = max(a[iao], b[i]);

            if (i == 0) {
                a[iao] = higher;
                b[i] = lower;
            } else {
                a[iao] = lower;
                b[i] = higher;
            }
        }
        
        // if it's in the results, cache the string to output later
        if (results.count(run)) {
            string result = "";
            for (int i=0; i<n; i++) {
                int iao = (i+ao)%n;
                int lower = min(a[iao], b[i]),
                    higher = max(a[iao], b[i]);
                result.append(to_string(lower) + " " + to_string(higher) + "\n");
            }
            results[run] = result;
            //cout << "run #" << run << "\n" << result << endl;
        }

        // array offset
        ao++;
    }

    // any queries for Ki>n
    for (int run=0; run<q; run++) {
        if (g[run] >= n) {
            string result = "";
            for (int i=0; i<n; i++) {
                int iao = (i+g[run])%n;
                int lower = min(a[iao], b[i]),
                    higher = max(a[iao], b[i]);
                result.append(to_string(lower) + " " + to_string(higher) + "\n");
            }
            results[g[run]] = result;
            //cout << results[g[i]] << "\n";
        }
    }

    for (int i=0; i<q; i++) {
        cout << results[g[i]] << "\n";
    }


    return 0;
}