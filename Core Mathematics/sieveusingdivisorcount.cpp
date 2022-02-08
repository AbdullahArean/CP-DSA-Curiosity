#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
const ll MAXN = 10;
ll DivisorCount[MAXN];
void DivisorCountTillnUsingSieve(){ //O(n^2)
    for (ll i = 1; i <= MAXN; i++) 
    for (ll j = i; j <= MAXN; j += i) 
        DivisorCount[j]++; //// here cnt[x] means count of divisors of x
    
}
int main(){
    DivisorCountTillnUsingSieve(); 
    //if div count is 2 then that is  a prime 
    for(int i=0;  DivisorCount[i]<=MAXN; i++) if(DivisorCount[i]==2) cout<<i<<endl;
    return 0;
}
