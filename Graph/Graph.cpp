#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAXN = 1e5, MOD = 1e9 + 7;
class Graph
{
    int numOfVertex;
    vector<int> adjlist[MAXN];

    // for BFS
    int distance[MAXN]; // distance from the source
    int visited[MAXN];  // 0=>never visited 1=>visiting 2=>done visited
    int previos[MAXN];  // Stores the immediate parent/previous y

    // for dfs
    int discoverytime[MAXN];
    int finishtime[MAXN];
    ll time;

public:
    Graph(int n_vertex)
    {
        this->numOfVertex = n_vertex;
    }
    void add_new_edge(int sourcenode, int destinationnode)
    {
        adjlist[sourcenode].push_back(destinationnode);
        // adjlist[destinationnode].push_back(sourcenode); // comment it out if it is a directed graph
    }
    bool detect_cycle_one_vertex(int currentnode, bool visited[], int parentnode)
    {
        visited[currentnode] = true;
        vector<int>::iterator itr;
        for (itr = adjlist[currentnode].begin(); itr != adjlist[currentnode].end(); itr++)
        {

            if (!visited[*itr])
            {
                if (detect_cycle_one_vertex(*itr, visited, currentnode))
                    return true;
            }
            else if (*itr != parentnode)
                return true;
        }
        return false;
    }
    bool detect_cycle_in_full_graph()
    {
        bool *visited = new bool[numOfVertex];
        for (int i = 0; i < numOfVertex; i++)
        {
            visited[i] = false;
        }
        for (int currentnode = 0; currentnode < numOfVertex; currentnode++)
            if (!visited[currentnode] && detect_cycle_one_vertex(currentnode, visited, -1))
                return true;
        return false;
    }
    bool isCycle()
    {
        vector<int> in_degree(numOfVertex, 0);
        for (int u = 0; u < numOfVertex; u++)
        {
            for (auto v : adjlist[u])
                in_degree[v]++;
        }
        queue<int> container_queue;
        for (int i = 0; i < numOfVertex; i++)
            if (in_degree[i] == 0)
                container_queue.push(i);
        int cnt = 1;
        vector<int> top_order;
        while (!container_queue.empty())
        {
            int u = container_queue.front();
            container_queue.pop();
            top_order.push_back(u);
            vector<int>::iterator itr;
            for (itr = adjlist[u].begin(); itr != adjlist[u].end(); itr++)
                if (--in_degree[*itr] == 0)
                {
                    container_queue.push(*itr);
                    cnt++;
                }
        }
        if (cnt != numOfVertex)
            return true;
        else
            return false;
    }
    void dfs()
    {
        for (int i = 1; i <= numOfVertex; i++)
        {
            visited[i] = 0;
            previos[i] = -1;
        }
        time = 0;
        int numberofconnectedcomponent = 0;
        for (int i = 1; i <= numOfVertex; ++i)
        {
            if (visited[i] == 0)
            {
                numberofconnectedcomponent++;
                cout << i << endl;
                dfs_visit(i);
            }
        }
        cout << numberofconnectedcomponent << endl;
    }
    void dfs_visit(int i)
    {
        time = time + 1;
        discoverytime[i] = time;
        visited[i] = 1;
        vector<int>::iterator it;
        for (it = adjlist[i].begin(); it != adjlist[i].end(); it++)
        {
            if (visited[*it] == 0)
            {
                previos[*it] = i;
                dfs_visit(*it);
            }
            visited[i] = 2;
            time = time + 1;
            finishtime[i] = time;
        }
    }
    void bfs(int x)
    { // Here x is the root vertex
        for (int i = 0; i < MAXN; i++)
        {
            visited[i] = 0; // 2 means black//1 means grey //0 means white
            previos[i] = -1;
            distance[i] = 0;
        }
        queue<int> container_queue;
        container_queue.push(x);
        visited[x] = 1;
        previos[x] = 0;
        distance[x] = 0;

        while (!container_queue.empty())
        {
            int y = container_queue.front();
            container_queue.pop();
            cout << y << endl;
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
    void printadjlist()
    {
        for (int i = 1; i < numOfVertex + 1; i++)
        {
            cout << i << " -> ";
            for (int x : adjlist[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    void printAllPaths(int s, int d)
    {

        // Create an array to store paths
        int *path = new int[numOfVertex];
        int path_index = 0; // Initialize path[] as empty

        // Initialize all vertices as not visited
        for (int i = 0; i < numOfVertex; i++)
            visited[i] = 0;

        // Call the recursive helper function to print all paths
        printAllPathsUtil(s, d, path, path_index);
    }
    void printAllPathsUtil(int u, int d, int path[], int &path_index)
    {
        // Mark the current y and store it in path[]
        visited[u] = 1;
        path[path_index] = u;
        path_index++;

        // If current vertex is same as destination, then print
        // current path[]
        if (u == d)
        {
            for (int i = 0; i < path_index; i++)
                cout << path[i] << " ";
            cout << endl;
        }
        else // If current vertex is not destination
        {
            // Recur for all the vertices adjacent to current vertex
            vector<int>::iterator i;
            for (i = adjlist[u].begin(); i != adjlist[u].end(); ++i)
                if (!visited[*i])
                    printAllPathsUtil(*i, d, path, path_index);
        }

        // Remove current vertex from path[] and mark it as unvisited
        path_index--;
        visited[u] = false;
    }
    void isBt(int x)
    {
        visited[x] = 1;
        distance[x] = 0;

        queue<int> container_queue;

        container_queue.push(x);

        while (!container_queue.empty())
        {
            int y = container_queue.front();

            container_queue.pop();

            vector<int>::iterator it;
            for (it = adjlist[y].begin(); it != adjlist[y].end(); it++)
            {
                if (visited[*it] == -1)
                {

                    visited[*it] = 1;
                    distance[*it] = !distance[y];
                    container_queue.push(*it);
                }
            }
        }
    }
    bool isBipartite()
    {
        for (int i = 1; i <= numOfVertex; ++i)
        {
            visited[i] = -1;
            distance[i] = -1;
        }
        for (int i = 1; i <= numOfVertex; i++)
            if (visited[i] == -1)
                isBt(i);

        for (int i = 1; i <= numOfVertex; i++)
        {
            for (auto it : adjlist[i])
            {
                if (distance[i] == distance[it])
                    return false;
            }
        }
        return true;
    }
    // void DFSUtil(int v)
    // {
    //     visited[v] = 1;
    //     cout << v << " ";
    //     vector<int>::iterator i;
    //     for (i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
    //         if (!visited[*i])
    //             DFSUtil(*i);
    // }
    // Graph getTranspose()
    // {
    //     Graph g(numOfVertex);
    //     for (int v = 1; v <= numOfVertex; v++)
    //     {
    //         vector<int>::iterator i;
    //         for (i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
    //         {
    //             g.adjlist[*i].push_back(v);
    //         }
    //     }
    //     return g;
    // }
    // void fillOrder(int v, stack<int> &Stack)
    // {
    //     visited[v] = 1;
    //     vector<int>::iterator i;
    //     for (i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
    //         if (visited[*i] == 0)
    //             fillOrder(*i, Stack);
    //     Stack.push(v);
    // }
    // void printSCCs()
    // {
    //     stack<int> Stack;
    //     for (int i = 1; i <= numOfVertex; i++)
    //         visited[i] = 0;
    //     for (int i = 1; i <= numOfVertex; i++)
    //         if (visited[i] == 0)
    //             fillOrder(i, Stack);
    //     Graph gr = getTranspose();
    //     for (int i = 1; i <= numOfVertex; i++)
    //         visited[i] = 0;
    //     while (Stack.empty() == false)
    //     {
    //         int v = Stack.top();
    //         Stack.pop();
    //         if (visited[v] == 0)
    //         {
    //             gr.DFSUtil(v);
    //             cout << endl;
    //         }
    //     }
    // }
};

int main()
{
    int n_nodes, n_edges, u, v;
    cin >> n_nodes;
    cin >> n_edges;
    Graph graph1(n_nodes);
    while (n_edges--)
    {
        cin >> u >> v;
        graph1.add_new_edge(u, v);
    }

    return 0;
}
