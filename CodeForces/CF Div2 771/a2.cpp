#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int tc;  cin >> tc;
  while (tc--){
    int n;  cin >> n;
    vector<int> a(n);
    for (int &ai: a) {
      cin >> ai;
    }

    int i = 0;
    while (i < n and a[i] == i + 1) {
      cout << a[i] << ' ';
      i++;
    }

    int x = i + 1;

    vector<int> p;
    while (i < n) {
      p.push_back(a[i]);
      if (a[i] == x) {
        i++;
        break;
      }
      i++;
    }

    reverse(p.begin(), p.end());

    while (i < n) {
      p.push_back(a[i++]);
    }

    for (int &pi: p) {
      cout << pi << ' ';
    }
    cout << '\n';
  }

}
