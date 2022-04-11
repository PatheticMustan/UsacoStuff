#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265

int main() {
    // z = (a + bi)^n
    // calculate (z^n)%m
    long long n, a, b;
    cin >> n >> a >> b;
    // mod
    long long m = 998244353;

    /** thoughts floating in my head
     * 
     * multiplying complex numbers
     * (a+bi)(c+di) = ac + adi + bci - bd
     *              = (ac-bd) + (ad+bc)i
     * a = ac - bd
     * b = ad + bc
     * (aRes + bRes[i])(a + b[i])
     * 
     * squaring complex numbers
     * z^2 = (a+bi)(a+bi)
     *     = aa + abi + abi - bb
     *     = (aa - bb) + (2ab)i
     * a = (aa-bb)
     * b = 2ab
     * 
     * !!!!!!! important
     * b^1011[2] = (b^1000[2])(b^10[2])(b^1[2])
     **/
    long long aRes = 1, bRes = 0;
    while (n) {
        //cout << aRes << " + " << bRes << "i       " << a << " + " << b << "i       ";
        if (n&1) {
            long long oldARes = aRes,
                      oldBRes = bRes;

            aRes = (oldARes*a - oldBRes*b) % m;
            bRes = (oldARes*b + oldBRes*a) % m;
        }
        long long oldA = a,
                  oldB = b;
        //cout << oldA*oldA << endl;
        a = (oldA*oldA - oldB*oldB) % m;
        b = (2*oldA*oldB) % m;
        n /= 2;
    }

    cout << ((aRes+m)%m) << " " << ((bRes+m)%m);

    return 0;
}