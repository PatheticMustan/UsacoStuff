#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    // left, right, pencil between left, or pencil between right
    // pencil between is only possible if x <= (b-a)
    if (x <= b-a) {
        cout << min(x-a, min(b, min(a, x-b)))+1;
    } else {
        cout << min(x-a, b)+1;
    }

    return 0;
}