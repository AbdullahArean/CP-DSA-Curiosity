/*
Problem Link  : Number Theory Sai Avinash Lecture
About Problem :
Tags          :
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
bool is_prime(int N){
    if(N==1) return false;
    for(int i=2; i*i<N; i++){
        if(N%i==0) return false;

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
            if(is_prime(i) && is_prime(N/i) && i!=N/i) return true;
            else return false;

        }
    }
    return false ;
    
}
void Solution()
{
    int n, ans=0;
    cin >> n;
    for(int i=4; i<=n; i++) ans+=is_almost_prime(i);
    printf("%d\n",ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}