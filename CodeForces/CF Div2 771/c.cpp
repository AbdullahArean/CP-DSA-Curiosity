/*
Problem Link  :
About Problem :
Tags          :
 */
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a
#define intinp(a) \
    int a;        \
    cin >> a;

// Disjoint Set Union Code
int parent[MAXN];
int size[MAXN];
void makeset(int v)
{
    /*
    To create a new set (operation make_set(v)),
    we simply create a tree with root in the vertex v,
     meaning that it is its own ancestor.
    */
    parent[v] = v;
    size[v] = 1;
}
int findset(int v)
{
    /*
        Finally the implementation of the find representative
        function (operation find_set(v)): we simply climb the
        ancestors of the vertex v until we reach the root, i.e.
        a vertex such that the reference to the ancestor leads to
        itself. This operation is easily implemented recursively.
    */
    if (v == parent[v])
        return v;
    // return findset(parent[v]); // Without Path Compression
    return parent[v] = findset(parent[v]);
    /*
    ****make the paths for all those nodes shorter, by setting the parent of each visited vertex directly to p.
    ****first find the representative of the set (root vertex), and then in the process of stack unwinding the visited
        nodes are attached directly to the representative.

    */
}
void unionset(int a, int b)
{
    /*
    To combine two sets (operation union_sets(a, b)), we first find
    he representative of the set in which a is located, and the
    representative of the set in which b is located. If the representatives
    are identical, that we have nothing to do, the sets are already merged.
    Otherwise, we can simply specify that one of the representatives is the
    parent of the other representative - thereby combining the two trees.
    */
    a = findset(a);
    b = findset(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void Solution()
{
    intinp(testcase);
    rep(i, 0, testcase)
    {
        vi ar;
        intinp(n);
        for(int i=1; i<n; i++)
        {
            int temp;
            cin >> temp;
            makeset(temp);
            ar.push_back(temp);
        }

        for(int i=1; i<=n; i++){
            for (int j = i + 1; j <= n && ar[i] > ar[j]; j++) 
            {
                unionset(ar[i], ar[j]);
            }

        } 
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (findset(ar[i]) == ar[i])
               { 
                    cout<<ar[i]<<endl;
                   count++;
                }
        }
        cout<<count<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}