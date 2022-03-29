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

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF INT_MAX
#define NIL -1

int d[MAXN];
short int color[MAXN];
vi adjl[MAXN];
int pre[MAXN];
void BFS(int number_of_edges, int source)
{
    
    for(int i=0; i<number_of_edges; i++)
    {
        color[i] = WHITE;
        pre[i] = NIL;
        d[i] = INF;
        
    }
    queue<int> Container_Queue;
    Container_Queue.push(source);
    color[source] = GREY;
    pre[source]= NIL;
    d[source]=0;
    while (!Container_Queue.empty())
    {
        int Node = Container_Queue.front();
        Container_Queue.pop();
        cout << Node <<" ";
      //  vector<int>::iterator it;
        for (auto it = adjl[Node].begin(); it != adjl[Node].end(); it++)
        {
            if (color[*it]==WHITE)
            {
                color[*it] = GREY;
                pre[*it]=Node;
                d[*it] = d[Node]+1;
                Container_Queue.push(*it);
            }
            color[Node]= BLACK;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int n, m, temp;
    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        if(i==0) temp=x;
        adjl[x].push_back(y);
//adjl[y].push_back(x); for undirected graph 
    }
    for(int i=0; i<n; i++)
    {

    BFS(n,i);
    cout<<endl;

    }

    return 0;
}