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

int dist[MAXN];
int vis[MAXN];
vi adjl[MAXN];
int pre[MAXN];
void Solution()
{
    rep(i, 0, MAXN)
    {
        vis[i] = 0; //2 means black//1 means grey //0 means white
        pre[i] = -1;
        dist[i] = 0;
        
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
    int x, y;
    cin>>x>>y;
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    pre[x]= 0;
    dist[x]=0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;
        vector<int>::iterator it;
        for (it = adjl[node].begin(); it != adjl[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                pre[*it]=node;
                dist[*it] = dist[node]+1;
                q.push(*it);
            }
            vis[node]= 2;
        }
    }
    if(dist[y]!=0){
        cout<<"There exist a path and the path is:"<<endl;
        stack<int> s1;
        int v= y;
        s1.push(v);
        while(pre[v]!=x){
            s1.push(pre[v]);
            v= pre[v];
        }
        s1.push(pre[v]);
        while(!s1.empty()) {cout<<s1.top()<<" "; s1.pop();}
        cout<<endl;

    }
    else {cout<<"No path exists"<<endl;}
    // rep(i, 1, n+1)
    // {
    //     cout<<i<<"=> visited: "<<vis[i] <<" Previous Node: "<<pre[i] <<" distance from 1: "<<dist[i]<<endl;
        
    // }
    //Check whether graph is connected or not
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}