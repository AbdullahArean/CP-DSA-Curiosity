#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MOD = 1e9 + 7;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

int discovery[MAXN];
int finishtime[MAXN];
int vis[MAXN];
vi adjl[MAXN];
int pre[MAXN];
void dfs()
{
  
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

      rep(i, 0, MAXN)
    {
        vis[i] = 0; //2 means black//1 means grey //0 means white
        pre[i] = -1;
        
    }
    int n, m, temp;
    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        if(i==0) temp=x;
        adjl[x].push_back(y);
//adjl[y].push_back(x);
    }
    cout << "Adjacency list of above matrix:" << endl;
    rep(i, 1, n + 1)
    {
        cout << i << " -> ";
        for (int x : adjl[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}