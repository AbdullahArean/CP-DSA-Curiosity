#include<bits/stdc++.h>
using namespace std;

class undirected_graph
{
    int vertex;
    list<int> *adjacencylist;
    bool check_c(int vertex, bool visitarr[], int r);

public:
    undirected_graph(int vertex); void add_new_edge(int v, int w); bool detect_cycle_in_full_graph();
};

undirected_graph::undirected_graph(int vertex)
{
    this->vertex = vertex;
    adjacencylist = new list<int>[vertex];
}

void undirected_graph::add_new_edge(int u, int v)
{
    
    adjacencylist[u].push_back(v);
    adjacencylist[v].push_back(u);
}


bool undirected_graph::check_c(int vertex,
                bool visitarr[], int r)
{
    
    visitarr[vertex] = true;
    list<int>::iterator itr;
    for (itr = adjacencylist[vertex].begin(); itr != adjacencylist[vertex].end(); itr++)
    {
        
        if (!visitarr[*itr])
        {
            if (check_c(*itr, visitarr, vertex))  return true;
        }
        else if (*itr != r) return true;
        
    }
    return false;
}

bool undirected_graph::detect_cycle_in_full_graph()
{
    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++)
        visited[i] = false;
    for (int u = 0; u < vertex; u++) if (!visited[u] && check_c(u, visited, -1)) return true;
    return false;
}

int main()
{
    int nnodes,nedges,U,vertex;
    cin>>nnodes;
    cin>>nedges;
    undirected_graph undirected_graph(nnodes);
    while(nedges--)
    {
        cin>>U>>vertex;
        undirected_graph.add_new_edge(U, vertex);
    }
    if(undirected_graph.detect_cycle_in_full_graph())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
