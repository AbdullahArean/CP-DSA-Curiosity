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
        int even1=-1, even2=-1;
        int odd1=-1, odd2=-1;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp%2==0)
            {
                even2= temp;
                if(even1!=-1 && even1>even2) {
                    flag=0;
                }
                even1= even2;

            }
            else 
            {
                odd2= temp;
                if(odd1!=-1 && odd1>odd2) {
                    flag=0;
                }
                odd1= odd2;

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