#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    int a[n - 1];
    for (int iter = 1; iter <= n - 1; iter++)
        cin >> a[iter];
    for (int iter = 1; iter <= t; iter += a[iter])
    {
        if (iter == t)
            return cout << "YES", 0;
    }
    cout << "NO";
}
