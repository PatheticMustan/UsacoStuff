#include <iostream>
using namespace std;

int main() {
        int n; cin >> n;
	int res = 0;

	for (int i=0; i<n; i++) {
		res ^= i+1;
	}

	for (int i=0; i<n-1; i++) {
		int p; cin >> p;
		res ^= p;
	}

	cout << res;
}
