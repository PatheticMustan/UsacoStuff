#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int c[m], remaining[m];
    bool north[m], south[m];
    for (int i=0; i<m; i++) {
        cin >> c[i];
        remaining[i] = 0;
        north[i] = true;
        south[i] = true;
    }

    for (int i=0; i<m; i++) {
        remaining[c[i]]++;
    }

    



    cout << "NO";

    return 0;
}