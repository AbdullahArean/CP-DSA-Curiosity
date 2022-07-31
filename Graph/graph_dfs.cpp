#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll MAXN=1e5;
class graph{
    int n;
    vector<int> adjlist[MAXN];
    ll time;
    ll d[MAXN];
    ll f[MAXN];
    ll v[MAXN];
    stack<ll> topostack;

    public: 
    graph(int n){
        this->n= n;
    }
    void add_new_edge(int s, int d){
        adjlist[s].push_back(d);
    }
    void dfs(){
        for(int i=0; i<n; i++){
            v[i]=0;
            f[i]= INT_MIN;
            d[i]=INT_MIN;
            //For Topological Sort
            while(!topostack.empty()) topostack.pop();
        }
        time=0;
        for(int i=0; i<n; i++){
            if(v[i]==0){
                dfs_visit(i);
            }
        }

    }
    void dfs_visit(int i){
        time++;
        d[i]=time;
        v[i]=1;
        for(auto it=adjlist[i].begin(); it!= adjlist[i].end(); it++){
            if(v[*it]==0)
            dfs_visit(*it);
        }
        v[i]=2;
        time++;
        f[i]= time;
        //For Topological Sort
        topostack.push(i);
        cout<<i<<endl;
    }
    void printadjlist()
    {
        for (int i = 0; i <n; i++)
        {
            cout << i << " : ";
            for (auto j : adjlist[i])
                cout << j << " ";
            cout << "\n";
        }
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; scanf("%d",&t);
    while(t--){

    }
    int n_nodes, n_edges, u, v;
    scanf("%d",&n_nodes);
    scanf("%d",&n_edges);
    graph graph1(n_nodes);
    while (n_edges--)
    {
        scanf("%d %d",&u, &v);
        graph1.add_new_edge(u, v);
    }
    graph1.printadjlist();
    graph1.dfs();
}