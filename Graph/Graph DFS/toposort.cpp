#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

const ll MAXN = 1e5;
class Graph
{
    int n;
    vector<int> adjlist[MAXN];

    int time;
    int d[MAXN], f[MAXN], v[MAXN], p[MAXN], low[MAXN];

    bool cycle;
    stack<int> topostack;

    vector<vector<int>> allpaths;
    vector<int> path;
    bool pathexists = false;

public:
    Graph(int n)
    {
        this->n = n;
    }
    void add(int s, int d)
    {
        adjlist[s].push_back(d);
        //adjlist[d].push_back(s);
    }
    void dfs_printallpath(int source, int dest)
    {
        v[source] = true;
        path.push_back(source);
        if (source == dest)
        {
            pathexists |= true;
            allpaths.push_back(path);
        }
        for (auto child : adjlist[source])
        {
            if (v[child] == 0)
                dfs_printallpath(child, dest);
        }
        path.pop_back();
        v[source] = false;
    }
    void artiutil(int vertex, int parent = -1)
    {
        v[vertex] = 1;
        time = time + 1;
        d[vertex] = time;
        low[vertex] = d[vertex];
        for (auto it = adjlist[vertex].begin(); it != adjlist[vertex].end(); it++)
        {
            int child = *it;
            if (child == parent)
                continue;
            if (v[child] == 0)
            {
                artiutil(child, vertex);
                low[vertex] = min(low[vertex], low[child]);
                if (low[child] > d[vertex])
                {
                    cout << vertex << " " << child << endl;
                }
            }
            // u->w
            else
            {
                low[vertex] = min(low[vertex], d[child]);
            }
        }
        v[vertex] = 2;
        time = time + 1;
        f[vertex] = time;
    }
    void artipoint()
    {
        for (int i = 0; i < n; i++)
        {
            v[i] = 0;
            p[i] = NULL;
            low[i] = INT_MIN;
            f[i] = INT_MIN;
            d[i] = INT_MIN;
        }
        time = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == 0)
                artiutil(j);
        }
    }
    void printallpath(int s, int d)
    {
        for (int i = 0; i < n; i++)
        {
            v[i] = 0;
        }
        dfs_printallpath(s, d);
        if (pathexists)
        {
            for (auto j : allpaths)
            {
                for (auto i : j)
                {
                    cout << i << " ";
                }
                cout<<endl;
            }
        }
    }
    Graph getTranspose()
    {
        Graph g(n);
        for (int i = 0; i < n; i++){
            for(auto j = adjlist[i].begin(); j!=adjlist[i].end();++i){
                g.add(*j,i);
            }
        }
        return g;
    }
    void fillorder(int vertex, bool vis[], stack<int>&st)
    {
        vis[vertex] = 1;
        for (auto child : adjlist[vertex])
        {
            if (vis[child] == 0)
                fillorder(child,vis,st);
        }
        st.push(vertex);
    }
    void dfsutilscc(int u)
    {
        v[u] = 1;
        cout << u << " ";
        for (auto w : adjlist[u])
        {
            if (v[w] == 0)
                dfsutilscc(w);
        }
    }
    void printscc()
    {
        stack<int> st;
        bool *vis = new bool[n];
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                fillorder(i, vis, st);
            }
        }
        Graph gt = getTranspose();
        for (int i = 0; i < n; i++)
        {
            v[i] = 0;
        }
        // while(!topostack.empty()){
        //     int w= topostack.top();
        //     //cout<<w<<endl;
        //     topostack.pop();
        //     if(v[w]==0){
        //         gt.dfsutilscc(w);
        //         cout<<endl;
        //     }

        // }

    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n_nodes, n_edges, u, v;
    scanf("%d", &n_nodes);
    scanf("%d", &n_edges);
    Graph graph1(n_nodes);
    while (n_edges--)
    {
        scanf("%d %d", &u, &v);
        graph1.add(u, v);
    }
    graph1.printscc();
}