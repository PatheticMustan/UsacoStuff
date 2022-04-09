#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, good = 0;
    cin >> n;
    string poop;

    while (n --> 0) {
        cin >> poop;
        if (poop == "good") good++;
    }

    cout << good;

    return 0;
}