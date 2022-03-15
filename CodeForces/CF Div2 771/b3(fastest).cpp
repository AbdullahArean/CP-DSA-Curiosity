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
        int even=-1;
        int odd=-1;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp%2==0)
            {
                if(even!=-1 && even>temp) {
                    flag=0;
                }
                even=temp;

            }
            else 
            {
               
                if(odd!=-1 && odd>temp) {
                    flag=0;
                }
                odd= temp;

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