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

    vvi adjm(n+1,vi(n+1,0));

    rep(i,0,m){
        int x, y;
        cin>>x>>y;
        adjm[x][y] =1;
        adjm[y][x] = 1;
    }
	cout<<"Adjacency Matrix of above matrix:"<<endl;
    rep(i,1,n+1)
    {
        rep(j, 1, n+1)
            cout<<adjm[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Give edge number to check connectivity"<<endl;
    int a,b;
    cin>>a>>b;
    if(adjm[a][b]==1) cout<<"There is an edge"<<endl;
    else cout<<"No Edge"<<endl;
    
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}