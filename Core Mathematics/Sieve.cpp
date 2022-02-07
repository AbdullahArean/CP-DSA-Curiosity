/*
Abdullah Ibne Hanif Arean
Link: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
bool prime[MAXN];

void SieveOfEratosthenes(int n)
{
    memset(prime, true, n);
    
    
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << "\n";
}
int main()
{
    int n=1000001;
    //cin>>n;
    SieveOfEratosthenes(n);
}