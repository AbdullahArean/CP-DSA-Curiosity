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
vi prefix_function(string s){
    int n = s.size();
    vi pi(n,0);
    for(int i=1;i<n; i++ ){
        int j=pi[i-1]; 
        while(j>0 and s[i]!=s[j]) j= pi[j-1];
        if(s[i]==s[j]) 
            j++;
        pi[i]=j;
    }
    return pi;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "na";
    int slen = s.size(); 
    vi res = prefix_function(s);
    // for(auto i: res ){
    //     cout<<i<<" ";
    // }    
    // cout<<"\n";
    string t= "apnacollege";
    int tlen = t.size();
    int pos = -1;
    int i(0), j(0);
    while (i<tlen)
    {
        if(t[i]==s[j]){
            j++;
            i++;
        }
        else{
            if(j!=0)
            {
                j=res[j-1];
            }
            else  i++;
        }
        if(j==slen){
            pos = i-slen;
            break;
        }
    }
    cout<<pos<<endl;
    
	
	return 0;
}