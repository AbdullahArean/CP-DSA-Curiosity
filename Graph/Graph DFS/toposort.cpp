#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

const ll MAXN=1e5;
class Graph{
    int n; 
    vector<int> adjlist[MAXN];

    int time;
    int d[MAXN], f[MAXN], v[MAXN];

    bool cycle;
    vector<int> topo;

    public:
    Graph(int n){
        this->n=n;
    }
    void add(int s , int d){
        adjlist[s].push_back(d);
    }
    void dfs(){
        for(int i=0; i<n; i++){
            v[i]=0;
            d[i]=-1;
            f[i]=-1;
        }
        cycle=false;
        time=0;
        for(int j=0; j<n; j++){
            if(v[j]==0) dfs_visit(j);
        }
        cout<<cycle<<endl;
        for(auto k:topo){
            cout<<k+1<<" ";
        }
        cout<<"\n";
    }
void dfs_visit(int u){
    time= time+1;
    d[u]=time;
    v[u]=1;
    //sort(adjlist[u].begin(), adjlist[u].end(), greater <>());
    for(auto ad :adjlist[u]){
        if(v[ad]==0){
            dfs_visit(ad);
        }
        else if(v[ad]==0){
            //
            cout<<u<<"   "<<ad<<endl;
            cycle=true;

        }
            
        }
    
    time=time+1;
    f[u]=time;
    v[u]=2;
    topo.push_back(u);
}

};
class graph{
    int n;
    vector<int> adjlist[MAXN];
    ll time;
    ll d[MAXN];
    ll f[MAXN];
    ll v[MAXN];
    vector<int> topo;
    bool cycle=false;


    public: 
    graph(int n){
        this->n= n;
    }
    void add_new_edge(int s, int d){
         adjlist[s].push_back(d);
    }
    void specialtoposort(){
        cycle= false;
        for(int i=0; i<n; i++){
            v[i]=0;
            f[i]= INT_MIN;
            d[i]=INT_MIN;
            //For Topological Sort
            //while(!topo.empty()) topo.pop();
        }
        time=0;
        for(int i=0; i<n; i++){
            if(v[i]==0){
                dfs_visit(i);
            }
        }
        if(!cycle){
            for(int p=topo.size()-1; p>=0; p++) cout<<topo[p]<<" ";
            cout<<"\n";
        }
        else{
            printf("Sandro fails.\n");
        }

    }
    void dfs_visit(int i){
        time++;
        d[i]=time;
        v[i]=1;
        sort(adjlist[i].begin(),adjlist[i].end());
        for (int j = adjlist[i].size() - 1; j >= 0; j--){
                if(v[adjlist[i][j]]==0) dfs_visit(adjlist[i][j]);
            }
        v[i]=2;
        time++;
        f[i]= time;
        //For Topological Sort
        topo.push_back(i);
        //cout<<i+1<<endl;
    }
    void printadjlist()
    {
        for (int i = 0; i <n; i++)
        {
            cout << i+1 << " : ";
        for(auto it=adjlist[i].begin(); it!= adjlist[i].end(); it++){
         cout << *it+1<< " ";
        }
        cout << "\n";
    }
    }
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n_nodes, n_edges, u, v;
    scanf("%d",&n_nodes);
    scanf("%d",&n_edges);
    Graph graph1(n_nodes);
    while (n_edges--)
    {
        scanf("%d %d",&u, &v);
        graph1.add(u-1, v-1);
    }
    graph1.dfs();
    
}