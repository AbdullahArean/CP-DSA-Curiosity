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
    long long int n,m;
    cin >> n >> m;
    long long int ans = (m*(m+1))/2 +m*(n-1)+(n*m*(n-1))/2;



    cout <<ans<<'\n';
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

  