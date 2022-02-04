/*
Author:Abdullah Ibne Hanif Arean
Problem: two poiter problem 3 (scaler youtube channel)
//Sort colors
*/
#include <bits/stdc++.h>
using namespace std;
void sortcolors(int arr[], int n)
{
    int st = 0, end = n - 1, i = 0;
    while (i <= end)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[st]);
            st++;
            //continue;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[end]);
            end--;
            continue;

        }
        i++;
    }
    
}
int main()
{
    int arr[] = {2, 2, 2, 0, 2, 1, 2, 1, 0, 0};
    int n = 10;
    sortcolors(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}