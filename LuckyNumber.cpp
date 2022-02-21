/*
Author: Abdullah Ibne Hanif Arean
Concept: Lucky Number (Precalculation)
        Links: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/M
Problem Link:

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> LuckyNumbers;
int f(int m)
{
    for (int i = 0; i < (1 << m); i++)
    { // for (int i = 0; i<pow(2,m); i++)
    int ans =0;
        for (int j = 0; j < m; j++)
        {
            
            if ((i & (1 << j)) > 0)
            {
                ans += 7 * pow(10, m - j-1 );
            }
            else
            {
                ans += 4 * pow(10, m - j-1);
            }
        }

        LuckyNumbers.push_back(ans);
        ans=1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        f(i);
    sort(LuckyNumbers.begin(),LuckyNumbers.end());
    for(int k=0; k<LuckyNumbers.size(); k++) cout<<LuckyNumbers[k]<<endl;
}