#include <bits/stdc++.h>
using namespace std;

int main() {
    // calculate (b^n)%m
    long long b, n, m;
    cin >> b >> n >> m;

    // b^1011[2] = (b^1000[2])(b^10[2])(b^1[2])
    long long res = 1;
    while (n) {
        if (n&1) res = (res*b) % m;
        b = (b*b) % m;
        n /= 2;
    }
    cout << res;

    return 0;
}