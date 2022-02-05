/*
Abdullah Ibne Hanif Arean 
Binary Exponentiation 
Link: https://cp-algorithms.com/algebra/binary-exp.html
*/
/*
Note*****what is (b&1)? https://stackoverflow.com/questions/50517336/cannot-understand-what-is-meant-by-b1-in-this-code-snippet-of-c
Note*****Left Shift :
Denoted as : << 
Eg: N<<i (N: first operand, i: second operand)
Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift. Or in other words left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’ is equivalent to multiplying x with 2^y (2 raised to power y). 
eg: lets take N=22; which is 00010110 in Binary Form.
Now, if “N is left-shifted by 2” i.e N=N<<2 then N will become N=N*(2^2). Thus, N=22*(2^2)=88 which can be wriiten as 01011000.
Note******Right Shift :
Denoted as : >>
Eg: N>>i (N: first operand, i: second operand)
Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift. In other words right shifting an integer “x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent to dividing x with 2^y. 
eg: lets take N=32; which is 100000 in Binary Form.
Now, if “N is right-shifted by 2” i.e N=N>>2 then N will become N=N/(2^2). Thus, N=32/(2^2)=8 which can be wriiten as 1000.
*/
#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b){
    if(b==0) return 1;
    long long res = binpow(a, b/2);
    if(b%2) return res*res*a;
    else return res*res;
}
long long binpowr(long long a, long long b) {
    long long res = 1;
    while (b > 0) { 
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1; //‘(x>>y)‘ is equivalent to dividing x with 2^y
    }
    return res;
}

int main(){

}