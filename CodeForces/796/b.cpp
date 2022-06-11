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
int numberoftwodivisor(int num){
    int ans=0;
    while(num%2==0){
        
        num=num/2;
        ans++;
    }
    return ans;

}
void Solution() {
    vector<int> v;
    int ans=0;
    int temp, min=INT_MAX;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(temp%2==0)v.push_back(temp);
    }
    if(v.size()==0){
        ans=0;
    }
    else if(v.size()==n){
        for(auto i:v) {
            int temp2 =numberoftwodivisor(i);
            if(temp2<min) min =temp2;
        }
        ans= min+ v.size()-1;

    }
    else if(v.size()<n){
        ans = v.size();
    }
    cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int testcase;
    cin>>testcase;
    while(testcase--)
    Solution();
	
	return 0;
}