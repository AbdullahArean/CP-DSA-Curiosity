#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first 
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a
typedef long long ll;
typedef pair<ll, ll> pi;
#define endl "\n"
const ll MAXEL = 2e5 + 5;

vector<ll> edges[MAXEL];
vector<pair<ll, ll>> edges1[MAXEL];
vector<ll> distanc;
vector<ll> visted;
vector<ll> coll;
vector<int> siz, parnt;
vector<ll> pathvis;
vector<ll> par;
char mat[52][52];

void DFSFuntion(int node, int n, int m)
{
    visted[node] = 1;
    mat[node / m][node % m] = '*';
    for (auto x : edges[node])
    {
        if (visted[x] == 0)
        {
            DFSFuntion(x, n, m);
        }
    }
}
class DSUClass
{
public:
    DSUClass(int n)
    {
        for (int iter = 0; iter <= n; iter++)
        {
            parnt.push_back(iter);
            siz.push_back(1);
        }
    }

public:
    int findpar(int node)
    {
        if (parnt[node] == node)
        {
            return node;
        }
        return parnt[node] = findpar(parnt[node]);
    }

public:
    void Union(int u, int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
        {
            return;
        }
        if (siz[pu] < siz[pv])
        {
            parnt[pu] = pv;
            siz[pv] += siz[pu];
        }
        else
        {
            parnt[pv] = pu;
            siz[pu] += siz[pv];
        }
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int iter = 0; iter < n; iter++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[iter][j];
        }
    }
    int a[n * m];
    DSUClass dsu(n * m - 1);
    visted.resize(n * m);

    for (int iter = 0; iter < n * m; iter++)
    {
        a[iter] = iter;
        visted[iter] = 0;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int iter = 0; iter < n; iter++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[iter][j] == '.')
            {
                visted[iter * m + j] = 1;
                for (int p = 0; p < 4; p++)
                {
                    int x1 = iter + dx[p];
                    int y1 = j + dy[p];
                    if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && mat[x1][y1] == '.')
                    {
                        dsu.Union(iter * m + j, x1 * m + y1);
                        edges[iter * m + j].push_back(x1 * m + y1);
                        edges[x1 * m + y1].push_back(iter * m + j);
                        visted[x1 * m + y1] = 1;
                    }
                }
            }
        }
    }
    set<int> set1;
    for (int iter = 0; iter < n * m; iter++)
    {
        if (visted[iter] == 1)
        {
            set1.insert(dsu.findpar(iter));
        }
    }
    set<int> set2;
    for (int iter = 0; iter < n; iter++)
    {
        if (mat[iter][0] == '.')
        {
            set2.insert(dsu.findpar(iter * m));
        }
        if (mat[iter][m - 1] == '.')
        {
            set2.insert(dsu.findpar(iter * m + m - 1));
        }
    }
    for (int iter = 0; iter < m; iter++)
    {
        if (mat[0][iter] == '.')
        {
            set2.insert(dsu.findpar(iter));
        }
        if (mat[n - 1][iter] == '.')
        {
            set2.insert(dsu.findpar(((n - 1) * m) + iter));
        }
    }
    vector<pair<int, int>> v;
    set<int>::iterator it;
    it = set1.begin();
    for (int iter = 0; iter < set1.size(); iter++)
    {
        if (set2.find(*it) == set2.end())
        {
            v.push_back({siz[*it], *it});
        }
        it++;
    }
    for (int iter = 0; iter < n * m; iter++)
        visted[iter] = 0;
    int x = set1.size() - set2.size();
    if (x == k)
    {
        cout << "0" << endl;
        for (int iter = 0; iter < n; iter++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[iter][j];
            }
            cout << endl;
        }
        return;
    }
    else
    {
        sort(v.begin(), v.end());
        x = x - k;
        int ans = 0;
        for (int iter = 0; iter < x; iter++)
        {
            ans += v[iter].first;
            DFSFuntion(v[iter].second, n, m);
        }
        cout << ans << endl;
        for (int iter = 0; iter < n; iter++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[iter][j];
            }
            cout << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}