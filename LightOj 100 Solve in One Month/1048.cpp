#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int nmax = 1e3+7;
const LL LINF = 1e17;

inline void optimizeIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int ara[nmax];
int n,k;

bool isPossible(int d)
{
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(d<ara[i])
            return false;

        if(sum+ara[i]<=d)
            sum += ara[i];
        else
            cnt++, sum = ara[i];
    }
    cnt++;
    return cnt<=k;
}

void printAns(int d)
{
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(sum+ara[i]<=d)
            sum += ara[i];
        else
        {
            printf("%d\n",sum);
            cnt++;
            sum = ara[i];
        }
        // not understood
        if(n-i+1==k-cnt) /** remaining num. of elements including this == the extra i need **/
        {
            printf("%d\n",sum);

            for(int j=i+1;j<=n;j++)
                printf("%d\n",ara[j]);

            break;
        }
    }
}

int main()
{

    //freopen("inp.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    optimizeIO();
    int tc;
    scanf("%d",&tc);
    for(int q=1; q<=tc; q++)
    {
        scanf("%d %d",&n,&k);
        n++, k++;

        int lo = 0, hi = 0, mid = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);

            lo = max(lo,ara[i]);
            hi += ara[i];
        }

        int ans = lo;

        while(lo<hi)
        {
            mid = (lo+hi)/2;
            if(isPossible(mid))
                hi = mid, ans = mid;
            else
                lo = mid+1;
        }
        printf("Case %d: %d\n",q,ans);

        printAns(ans);

    }


    return 0;
}