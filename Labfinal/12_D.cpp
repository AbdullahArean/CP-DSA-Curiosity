#include<bits/stdc++.h>
using namespace std;

#define MAXIMUM 260
#define Infinity 1000000000
int arr1[MAXIMUM], dyps[MAXIMUM], dyp[MAXIMUM][MAXIMUM];
int dpCost(int i, int j)
{
    if(j<i)
        return 0;
    return dyps[j]-dyps[i]+arr1[i];
}
int solve(int i , int j)
{
    if(i==j || i>j)
        return 0;
    if(dyp[i][j]!=-1)return dyp[i][j];
    int ans=Infinity;
    for (int k=i; k<=j; k++)
    {
 
        ans = min(ans , solve(i,k-1)+dpCost(i,k-1) + solve(k+1,j)+dpCost(k+1,j));
 
    }
    return dyp[i][j]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d",&arr1[i]);
 
        fill(&dyp[0][0],&dyp[n+1][n+1],-1);
        fill(&dyps[0],&dyps[n+1],0);
        dyps[0]=arr1[0];
        for (int i=1; i<n; i++)
            dyps[i]=dyps[i-1]+arr1[i];
        printf("%d\n",solve(0,n-1));
 
    }
 
    return 0;
}