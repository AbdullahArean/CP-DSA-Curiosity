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
int josephus(int n, int k) {
    return n > 1 ? (josephus(n-1, k) + k - 1) % n + 1 : 1;
}
int j( int n, int k){
	if(n==0) return 0;
	return (j(n-1,k)+k)%n;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

	//cout<<josephus(5,2);
	cout<<j(5,2);
	
	return 0;
}