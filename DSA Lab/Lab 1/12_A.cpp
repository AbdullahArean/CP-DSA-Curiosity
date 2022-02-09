//12
//12
//12
//12
//12
//12
//12
//12
//12
//12
#include <bits/stdc++.h>
#define Maxx 100000

using namespace std;
long int sumrecursion(long int arr[], int p)
{
    if (p == 0)
        return 0;

    return arr[p - 1] + sumrecursion(arr, p - 1); 
}
int main()
{
    long int arr[Maxx];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    printf("%ld\n", sumrecursion(arr, n)); //sum(arr,5)
}
