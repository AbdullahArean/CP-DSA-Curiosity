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
		
		printf("Case %d:\n", i+1);
	}
	
	
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	//Solution();

    string s = "ma";
    string p = "ma ma sma osamaa";
    int S = s.size(); int P = p.size();
    for(int i=0; i<P-S+1; i++){
    if(p.substr(i,S)==s){
        cout<<"Found match at "<< i<< endl;
    }
    }
	return 0;
}