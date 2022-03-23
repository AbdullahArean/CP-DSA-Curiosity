//12
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
        vis[i] = 0; // 2 means black//1 means grey //0 means white
        pre[i] = -1;
        dist[i] = 0;
    }
    int n, m, temp;
    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        if (i == 0)
            temp = x;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
    q.push({0,0});
    vis[0] = 1;
    pre[0] = 0;
    dist[0] = 0;
    while (!q.empty())
    {
        int node = q.top().second;
        int dis=q.top().first;
        q.pop();
        // cout << node << endl;
        vector<int>::iterator it;
        for (it = adjl[node].begin(); it != adjl[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                pre[*it] = node;
                dist[*it] = dist[node] + 1; 
                q.push({dis+1,*it});
            }
            vis[node] = 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        if (i == 0)
        {
            cout << "0"
                 << endl;
        }
        else if (dist[i] != 0)
        {
            stack<int> s1;
            int v = i;
            s1.push(v);
            while (pre[v] != 0)
            {
                s1.push(pre[v]);
                v = pre[v];
            }
            s1.push(pre[v]);
            while (!s1.empty())
            {
                cout << s1.top();
                s1.pop();
                if(!s1.empty()) cout<<" ";
            }
            cout << endl;
        }
        else
        {
            cout << "Not Reachable" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}