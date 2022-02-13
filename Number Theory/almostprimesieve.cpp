/*
Problem Link  : Number Theory Sai Avinash Lecture
About Problem :
Tags          :
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8;

int spf[MAXN];
void SmallestPrimeFactor(int n)
{
    memset(spf, 0, n);
    spf[0] = -1;
    spf[1] = -1;
    for (int p = 2; p * p <= n; p++)
    {
        if (spf[p] == 0)
        {
            for (int i = p * p; i <= n; i += p)
                spf[i] = p;
        }
    }
}
bool is_prime(int N)
{
    if (N == 1)
        return false;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
bool is_almost_prime(int N)
{
    int LIM = sqrt(N);

    for (int i = 2; i <= LIM; i++)
    {
        if (N % i == 0)
        {
            // i is a prime
            // N/i is a prime
            // i!=N/i
            if (is_prime(i) && is_prime(N / i) && i != N / i && (i*(N/i)==N))
                return true;
            else
                return false;
        }
    }
    return false;
}
void Solution()
{
    int n = 100000, ans = 0;
    SmallestPrimeFactor(n);
    for (int i = 2; i < n; i++)
    {
            //if(is_almost_prime(i)) ans++;
             
            if((spf[i] != 0) && !(spf[(int)i/spf[i]]) && spf[i]!=(int)i/spf[i])ans++;
        
    }
    cout<<ans<<endl;
    // cout<<is_prime(4)<<endl;
    // cout<<is_almost_prime(8)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}