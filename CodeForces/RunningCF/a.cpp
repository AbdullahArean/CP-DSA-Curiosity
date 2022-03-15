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
    int t; cin>>t;
    while(t--){
	int s,n;
	cin>>n>>s;
    int k=s,count=0;
    while(k>0){
        k-=n*n;
        count++;
        if(k-n*n<0) break;
    }
    cout<<count<<endl;
    }
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}