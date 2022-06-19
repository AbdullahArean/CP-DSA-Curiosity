#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 2*100005, MOD = 1e9 + 7;
ll outdeg[MAXN];
// Edges starts from 0 to N-1
class Graph
{
    int numOfVertex;
    vector<int> adjlist[MAXN];

    // for BFS
    int distance[MAXN]; // distance from the source
    int visited[MAXN];  // 0=>never visited 1=>visiting 2=>done visited
    int previos[MAXN];  // Stores the immediate parent/previous y

    
public:
    Graph(int n_vertex)
    {
        
        this->numOfVertex = n_vertex;
    }
    void add_new_edge(int sourcenode, int destinationnode)
    {
        
        adjlist[sourcenode].push_back(destinationnode);
       // outdeg[sourcenode]++;
    }
    void bfs(int x)
    { // Here x is the root vertex
        for (int i = 0; i < MAXN; i++)
        {
            visited[i] = 0; // 2 means black//1 means grey //0 means white
            previos[i] = INT_MIN;
            distance[i] = INT_MIN;
        }
        queue<int> container_queue;
        container_queue.push(x);
        visited[x] = 1;
        previos[x] = -1;
        distance[x] = 0;

        while (!container_queue.empty())
        {
            int y = container_queue.front();
            container_queue.pop();
            // cout << y << endl;
            vector<int>::iterator it;
            for (it = adjlist[y].begin(); it != adjlist[y].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = 1;
                    previos[*it] = y;
                    distance[*it] = distance[y] + 1;
                    container_queue.push(*it);
                }
                visited[y] = 2;
            }
        }
    }
    int cf800div2e(int source, int destination)
    {
        bfs(source);
        if (distance[destination] == INT_MIN)
            cout << "No Path Exists" << endl;
        else
        {
            stack<int> ans;
            int iterator = destination;
            while (previos[iterator] != -1)
            {
                ans.push(iterator);
                iterator = previos[iterator];
            }
            ans.push(iterator);
            int result =0;
            while (!ans.empty())
            {
                int temp= ans.top();
                ans.pop();
                if(!ans.empty())
                {result+=outdeg[temp];}
                
            }
            return result;
        }
        return -1;
    }
};
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	 int n_nodes, n_edges, u, v;
    cin >> n_nodes; //cities
    cin >> n_edges; //roads
    Graph graph1(n_nodes);
    set<pair<int,int>> container;
    for(int i=0; i<n_nodes; i++) outdeg[i]=0;
    while (n_edges--)
    {
        cin >> v >> u;
        if(container.find(make_pair(v-1,u-1))==container.end()){
            graph1.add_new_edge(v-1, u-1);
            container.insert(make_pair(v-1, u-1));
            outdeg[v-1]+=1;
        }
        
    }
    cout<<graph1.cf800div2e(0,n_nodes-1)<<endl;
	
 	return 0;
}