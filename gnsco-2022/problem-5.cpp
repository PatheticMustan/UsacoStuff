#include <bits/stdc++.h>
using namespace std;

int main() {
    long long b, n, m;
    cin >> b >> n >> m;

    long long res = 1;
    while (n) {
        if (n&1) res = (res*b) % m;
        b = (b*b) % m;
        n /= 2;
    }
    cout << res;

    return 0;
}