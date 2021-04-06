#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    int moves = 0;
    
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        arr[i] = t;
    }

    for (int i=1; i<n; i++) {
        if (arr[i-1] > arr[i]) {
            moves += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout << moves;
}
