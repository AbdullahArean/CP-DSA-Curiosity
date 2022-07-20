#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 100000;

int SolutionForAssumedInput(int a, int b, int assume)
{
    int a= assume*a;
    int b= assume*b;
    int peri= 2*(a+b);
    if(peri<400) return -1;
    if(peri>400) return +1;
    else return 0;
}
int BinarySearchOnRealLifeProblems()
{
    int lo, hi, mid; // Define The Search Space
    while (hi > lo)
    {
        int mid = lo + (hi - lo) / 2;
    }
    return lo;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcase;
    cin >> testcase;
    getchar();
    for (int i = 0; i < testcase; i++)
    {
        double a,b;
        scanf("%lf : %lf",&a,&b);

    }
}