#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>> &edges)
{
    // https://leetcode.com/problems/find-center-of-star-graph/
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    else
        return edges[0][1];
}
int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    // https://leetcode.com/problems/maximal-network-rank/
    vector<unordered_set<int>> adjlist(n);
    int ans = INT_MIN;
    for (auto i : roads)
    {
        adjlist[i[0]].insert(i[1]);
        adjlist[i[1]].insert(i[0]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = adjlist[i].size() + adjlist[j].size();
            if (adjlist[j].count(i))
            {
                --temp;
            }
            if (ans < temp)
                ans = temp;
        }
    }
    return ans;
}
int minTrioDegree(int n, vector<vector<int>> &edges)
{
    vector<unordered_set<int>> adjlist(n);
    int ans = -1;
    for (auto i : edges)
    {
        adjlist[i[0]].insert(i[1]);
        adjlist[i[1]].insert(i[0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n && adjlist[j].count(i); j++)
        {
            for (int k = j + 1; k < n && adjlist[k].count(i) && adjlist[k].count(j); k++)
            {
                set<int> s;
                for (auto p : adjlist[i])
                    s.insert(p);
                for (auto q : adjlist[j])
                    s.insert(q);
                for (auto r : adjlist[k])
                    s.insert(r);
                int temp = s.size() - 3;
                if (ans < temp)
                    ans = temp;
            }
        }
    }
    return ans;
}
int main()
{
    int num_row = 5, num_col = 6;
    // Initializing the 2-D vector
    vector<vector<int>> v{{1, 2}, {2, 3}, {4, 2}};
    vector<vector<int>> v1{{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
    std::cout<<minTrioDegree(6,v1);

}