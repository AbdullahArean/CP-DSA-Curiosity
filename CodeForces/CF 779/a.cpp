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

int n;
string s;
vector<int> v;
 
void Solution() {
    v.clear();
    cin >> n >> s;
    int ans = 0;
    rep(i,0,n) {
        if (s[i] == '0') v.push_back(i);
    }
    rep (i ,0, (int)v.size() - 1) {
        if (v[i + 1] - v[i] <= 2) ans += 2 - (v[i + 1] - v[i]) + 1;
    }
    cout << ans << '\n';
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