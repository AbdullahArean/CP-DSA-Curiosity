#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MOD=1e9+7;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vi>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

void Solution(){
    int n,m;
    cin>>n>>m;

    vi adjl[MAXN];

    rep(i,0,m){
        int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
	cout<<"Adjacency list of above matrix:"<<endl;
    rep(i,1,n+1)
    {
        cout<<i<<" -> ";
        for(int x: adjl[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<"Give edge number to check connectivity"<<endl;
    int a,b;
    cin>>a>>b;
    bool flag= false;
    for(int x: adjl[a]){
        {if(x==b) cout<<"There is an direct edge between "<<a<<" to "<<b<<endl; flag=true;}
    }
    // for(int x: adjl[b]){
    //     {if(x==a) cout<<"There is an direct edge between "<<b<<" to "<<a<<endl; flag= true;}
    // }
    if(flag==false) cout<<"No direct edge between "<<a<<" to "<<b<<""<<endl; 
    
    
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}