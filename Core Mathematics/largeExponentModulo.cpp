/*
Abdullah Ibne Hanif Arean 
Binary Exponentiation 
Link: https://cp-algorithms.com/algebra/binary-exp.html
*/
/*
###########333Effective computation of large exponents modulo a number
Problem: Compute . This is a very common operation. For instance it is used in computing
 the modular multiplicative inverse.
Note :a*b congruent to (a modulo m)*(b modulo m)(modulo m)
Solution: Since we know that the module operator doesn't interfere with multiplications (), 
we can directly use the same code, and just replace every multiplication with a modular multiplication:
*/
#include<bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){

}