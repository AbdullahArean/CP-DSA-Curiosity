#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
const ll MAXN = 1e8;
ll DivisorCount[MAXN];
void DivisorCountTillnUsingSieve(){
    for (ll i = 1; i <= MAXN; i++) 
    for (ll j = i; j <= MAXN; j += i) 
        DivisorCount[j]++; //// here cnt[x] means count of divisors of x
    
}
int main(){
    DivisorCountTillnUsingSieve();
    for(int i=0; i<=MAXN; i++) cout<<i<<" "<<DivisorCount[i]<<endl;
    return 0;
}
