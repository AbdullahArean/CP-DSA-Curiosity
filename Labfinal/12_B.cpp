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
int n, m, a;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while (n < m)
        m % 2 ? m++ : m /= 2, a++;
    cout << a + n - m;
}