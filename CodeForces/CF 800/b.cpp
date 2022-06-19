/*
Problem Link  : 
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

ll Solution(){
    ll n;
    string s;
    cin>>n>>s;
    s="a"+s;
    ll ans=0;
    for(ll i=n;i>=1;i--){
        if(s[i]!=s[i-1]){
            ans+=i;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int testcase;
    cin>>testcase;
    while(testcase--)
    Solution();
	
	return 0;
}