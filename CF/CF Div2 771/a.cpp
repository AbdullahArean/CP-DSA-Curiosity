
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

void Solution()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, l, r;
        cin >> n;
        int arr[1000];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        //My Solutions Started From Here
        for (int p = 1; p <= n; p++)
        {
            if (arr[p] != p)
            {
                l = p; // cout<<l;
                for (int j = p + 1; j <= n; j++)
                {
                    // cout<<" "<<r<<endl;
                    if (arr[j] == l)
                    {
                        r = j;
                        break;
                    }
                }
                break;
            }
        }
        while (l < r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        for (int h = 1; h <= n; h++)
            cout << arr[h] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}