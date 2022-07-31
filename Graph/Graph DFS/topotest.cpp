#include<bits/stdc++.h>
using namespace std;
#define mx 10009
#define white 0
#define gray 1
#define black 2
vector < int > graph[mx];
int color[mx];
bool cycle;
vector < int > result;
void dfs(int node)
{
    color[node] = gray;
    sort(graph[node].begin(), graph[node].end());
    for (int i = graph[node].size() - 1; i >= 0; i--)
    {
        int next = graph[node][i];
        if (color[next] == white)
        {
            dfs(next);
        }
        else if (color[next] == gray)
        {
            cycle = true;
            return ;
        }
    }
    color[node] = black;
    result.push_back(node);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cycle = false;
    int node,edge;
    scanf("%d%d", &node, &edge);
    for (int i = 1; i <= edge; i++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
    }
 
    for (int i = node; i >= 1; i--)
    {
        if (color[i] == white)
            dfs(i);
    }
    if (cycle == true)
    {
        printf("Sandro fails.\n");
    }
    else
    {
        for (int i = result.size() - 1; i >= 0; i--)
        {
            printf("%d ", result[i]);
        }
        cout<<endl;
    }
    return 0;
}