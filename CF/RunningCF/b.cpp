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

void Solution(){
	int n;
	cin>>n;
	for(int i=0 ; i<n; i++){
		int n, ar[(int)1e6];
        rep(i,0,n) cin>>ar[n];
        sort(ar, ar+n);
        int sum=ar[0], pre[(int)1e6], post[(int)1e6];
        rep(i+1, 0, n) pre[i]=sum; sum

	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}