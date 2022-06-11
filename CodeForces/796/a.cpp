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
int getBit(int n, int pos){
    return((n & (1<<pos))!=0);
}
int setBit(int n, int pos){
    return n|(1<<pos);
}
int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}
int  toggleBit(int n, int pos){
    if(getBit(n,pos))
    return clearBit(n,pos);
    else return setBit(n,pos);

}
void Solution() {
    cin >> n;
    int ans = 0;
    if(getBit(n,0)==1){
        ans = setBit(ans,0);
        if(clearBit(n,0)<=0) 
            ans = setBit(ans,1);
    }
    else{
        int i=0;
        while(getBit(n,i)== false) i++;
        ans=setBit(ans,i);
        if(clearBit(n,i)<=0) 
            ans = setBit(ans,0);
    }
    cout <<ans << '\n';

}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int testcase;
    cin>>testcase;
    while(testcase--)
   { Solution();}
	
	return 0;
}