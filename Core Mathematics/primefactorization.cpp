/*
//The following function factors constructs a vector that contains the prime 
factor- ization of n. The function divides n by its prime factors, 
and adds them to the vector. The process ends when the remaining number 
n has no factors between 2 and root(N).
 If n > 1, it is prime and the last factor.

 Note that
 each prime factor appears in the vector as many times as it divides the number. 
 For example, 24 = 23 · 3, so the result of the function is [2, 2, 2, 3].
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> factors(int n) 
{
    vector<int> f;
    for (int x = 2; x*x <= n; x++) 
    {
        while (n%x == 0)
        {
            f.push_back(x);
            n /= x; 
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}
int gcdfromfactor(int a, int b){
    int gcd=1;
    vector<int> A = factors(a);
    vector<int> B = factors(b);
    int it1=0, it2=0;
    while(it1<A.size() && it2<B.size()){
        if(A[it1]==B[it2]){
            gcd *= A[it1];
            it1++; it2++;

        }
        else if(A[it1]<B[it2]) it1++;
        else it2++;
    }
    return gcd;
}
int lcdfromfactor(int a, int b)
{return (a*b)/gcdfromfactor(a,b);}

int main()
{
    // vector<int> ans = factors(34);
    // for(int i=0; i<ans.size(); i++) cout<<ans[i]<<endl;
    cout<<gcdfromfactor(8,12)<<endl; 
    cout<<lcdfromfactor(8,12)<<endl;
}