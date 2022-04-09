#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int blah, good = 0;

    for (int i=0; i<n; i++) {
        cin >> blah;
        if (blah >= 93) good++;
    }

    cout << max((n-good)-(good*k), 0);

    return 0;
}