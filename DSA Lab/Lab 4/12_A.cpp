//12
//12
//12
//12
//12
#include <bits/stdc++.h>
using namespace std;
int f(int m)
{
    for (int i = 0; i<(1<<m); i++) {
        for (int j = 0; j<m; j++) {
            if ( (i& (1<<j)) > 0) {
                cout<<7;
            } else {
                cout<<4;
            }
        }

        cout<< endl;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) f(i);
    
}