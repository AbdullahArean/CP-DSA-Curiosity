/*
Problem Link  : 
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a


void Solution() {
    int n, k;
     cin>>n>>k;
     vi a(n);
     rep(i,0, n) cin>>a[i];
     pqmaxi(pq);
     rep(i, 0, n)
     {
        pq.push(a[i]);
        if(pq.size()>k) pq.pop();
     } 
    cout<<pq.top()<<endl;
    

    
}
	

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution();
	
	return 0;
}