#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int g[n];
    int blah, good = 0;

    // get input
    for (int i=0; i<n; i++) {
        cin >> blah;
        g[i] = blah;
        if (blah >= 93) good++;
    }

    // sort Gi from lowest to greatest, split into good and bad (Gi>=93)
    // lowest good, followed by k lowest bad
    // edgecase for k=0, then it's just sorted lowest to greatest
    int goodGrades[good];
    int badGrades[n-good];
    int gi = 0, bi = 0;
    
    for (int i=0; i<n; i++) {
        g[i] >= 93?
            goodGrades[gi++] = g[i] :
            badGrades[bi++] = g[i];
    }
    sort(goodGrades, goodGrades+gi);
    sort(badGrades, badGrades+bi);

    gi = 0, bi = 0;

    for (int i=0; i<((n-good)-(good*k)); i++) {
        cout << badGrades[bi++] << " ";
    }
    for (int i=0; i<good; i++) {
        cout << goodGrades[gi++] << " ";
        for (int o=0; o<k; o++) {
            if (bi < n-good) cout << badGrades[bi++] << " "; 
        }
    }


    return 0;
}