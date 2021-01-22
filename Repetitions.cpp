#include <iostream>
using namespace std;

int main() {
	int longest = 0;
	int cc = 0;
	char current;
        string s; getline(cin, s);

	for (int i=0; i<s.length(); i++) {
		if (s[i] != current) {
			cc = 1;
			current = s[i];
		} else {
			cc++;
		}

		longest = max(longest, cc);
	}

	cout << longest;
}
