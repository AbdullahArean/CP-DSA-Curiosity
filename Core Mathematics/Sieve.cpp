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
    prime[0] =false;
    prime[1]=false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    int n=1000001;
    SieveOfEratosthenes(n);
}