#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2;

void Solution()
{
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool flag= 1;
        int n, temp;
        cin >> n;
        stack<int> even;
        stack<int> odd;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp%2)
            {
                if(odd.size()>0 && odd.top()>temp) {
                    flag=0;
                }
                odd.push(temp);

            }
            else {
                if(even.size()>0 && even.top()>temp) {
                    flag=0;
                }
                even.push(temp);

            }

        }

    if(flag) printf("Yes\n");
        else printf("No\n");
        
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution();

    return 0;
}