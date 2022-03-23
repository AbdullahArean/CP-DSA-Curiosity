#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MOD = 1e9 + 7;
class Graph
{
    int numOfVertex;
    vector<int> adjlist[MAXN];

    // for BFS
    int distance[MAXN]; // distance from the source
    int visited[MAXN];  // 0=>never visited 1=>visiting 2=>done visited
    int previos[MAXN];  // Stores the immediate parent/previous node

public:
    Graph(int n_vertex)
    {
        this->numOfVertex = n_vertex;
    }
    void add_new_edge(int sourcenode, int destinationnode)
    {
        adjlist[sourcenode].push_back(destinationnode);
        adjlist[destinationnode].push_back(sourcenode); // comment it out if it is a directed graph
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
    // Detect Cycle in a Directed Graph using BFS and indegree
    bool Graph::isCycle()
    {
        // Create a vector to store indegrees of all
        // vertices. Initialize all indegrees as 0.
        vector<int> in_degree(numOfVertex, 0);

        // Traverse adjacency lists to fill indegrees of
        // vertices. This step takes O(V+E) time
        for (int u = 0; u < numOfVertex; u++)
        {
            for (auto v : adjlist[u])
                in_degree[v]++;
        }

        // Create an queue and enqueue all vertices with
        // indegree 0
        queue<int> q;
        for (int i = 0; i < numOfVertex; i++)
            if (in_degree[i] == 0)
                q.push(i);

        // Initialize count of visited vertices
        // 1 For src Node
        int cnt = 1;

        // Create a vector to store result (A topological
        // ordering of the vertices)
        vector<int> top_order;

        // One by one dequeue vertices from queue and enqueue
        // adjacents if indegree of adjacent becomes 0
        while (!q.empty())
        {

            // Extract front of queue (or perform dequeue)
            // and add it to topological order
            int u = q.front();
            q.pop();
            top_order.push_back(u);

            // Iterate through all its neighbouring nodes
            // of dequeued node u and decrease their in-degree
            // by 1
            vector<int>::iterator itr;
            for (itr = adjlist[u].begin(); itr != adjlist[u].end(); itr++)

                // If in-degree becomes zero, add it to queue
                if (--in_degree[*itr] == 0)
                {
                    q.push(*itr);
                    // while we are pushing elements to the queue we will incrementing the cnt
                    cnt++;
                }
        }

        // Check if there was a cycle
        if (cnt != numOfVertex)
            return true;
        else
            return false;
    }
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
    if (graph1.detect_cycle_in_full_graph())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
