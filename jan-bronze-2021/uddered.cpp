#include <iostream>
using namespace std;
#include <string>
 
int main() {
    // example 
    // abcdefghijklmnopqrstuvwxyz
    // mood
    string alphabet; getline(cin, alphabet);
    string letters; getline(cin, letters);
    int last = -1;
    int times = 1;

    // loop through letters
    for (int i=0; i<letters.length(); i++) {
        int index = alphabet.find(letters[i]);
        
        if (index <= last) {
            times++;
        }

        last = index;
    }
    
    cout << times;
}
