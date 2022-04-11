#include <bits/stdc++.h>
using namespace std;

int main() {
    // mod
    long long m = 998244353;

    long long n;
    long long b[11], c[11];
    cin >> n;
    for (int i=0; i<11; i++) cin >> b[i];
    for (int i=0; i<11; i++) cin >> c[i];

    long long a[11][11];
    // this is so yucky, it makes me shiver with delight
    // i think this is why i love javascript so much, i can do things like this but much worse
    for (int i=0; i<11; i++) for (int o=0; o<11; o++) cin >> a[i][o];

    



    // https://en.wikipedia.org/wiki/Identity_matrix
    // i don't really understand any of this math but i think if i read enough i can get a monkey understanding
    long long result[11][11], temp[11][11];
    // mmmmmm delicious, this makes a zero'd matrix but with a diagonal line of 1s
    for (int i=0; i<11; i++) for (int o=0; o<11; o++) result[i][o] = (i==o? 1 : 0);

    // b^1011[2] = (b^1000[2])(b^10[2])(b^1[2])
    while (n) {
        // multiply result with original matrix
        if (n&1) {
            // square original matrix
            for (int i=0; i<11; i++) {
                for (int o=0; o<11; o++) {
                    // add up row of i, col of o
                    temp[i][o] = 0;
                    for (int k=0; k<11; k++) temp[i][o] += (result[i][k] * a[k][o]);
                }
            }
            // copy temp to a
            for (int i=0; i<11; i++) for (int o=0; o<11; o++) result[i][o] = temp[i][o] % m;
        }

        // square original matrix
        for (int i=0; i<11; i++) {
            for (int o=0; o<11; o++) {
                // add up row of i, col of o
                temp[i][o] = 0;
                for (int k=0; k<11; k++) temp[i][o] += (a[i][k] * a[k][o]) % m;
            }
        }
        // copy temp to a
        for (int i=0; i<11; i++) for (int o=0; o<11; o++) a[i][o] = temp[i][o] % m;


        
        n /= 2;
    }


    // multiplying by vector B
    // Alpha Lyrae...!
    long long iLoveStars[11];

    for (int i=0; i<11; i++) {
        iLoveStars[i] = 0;
        for (int o=0; o<11; o++){
            iLoveStars[i] += (result[i][o] * b[o]) % m;
        }
    }



    // the culmination of all our efforts
    long long starryEyed = 0;
    for (int i=0; i<11; i++) starryEyed += (iLoveStars[i] * c[i]) % m;
    starryEyed = starryEyed % m;

    // gg
    cout << starryEyed << endl;


    return 0;
}
