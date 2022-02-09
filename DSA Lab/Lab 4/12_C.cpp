//12
//12
//12
//12
//12
//12
//12
//12
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = 1000009;
int LOWER_BOUND(int arr[], int N, int X)
{
    int MIDELEMENT;
    int LOW = 0;
    int HIGH = N;
    while (LOW < HIGH) {
        MIDELEMENT = LOW + (HIGH - LOW) / 2;
        if (X <= arr[MIDELEMENT]) {
            HIGH = MIDELEMENT;
        }
        else {
            LOW = MIDELEMENT + 1;
        }
    }
    if(LOW < N && arr[LOW] < X) {
       LOW++;
    }
    return LOW;
}
int UPPER_BOUND(int arr[], int N, int X)
{
    int MIDELEMENT;
    int LOW = 0;
    int HIGH = N;
    while (LOW < HIGH) {
        MIDELEMENT = LOW + (HIGH - LOW) / 2;
        if (X >= arr[MIDELEMENT]) {
            LOW = MIDELEMENT + 1;
        }
        else {
            HIGH = MIDELEMENT;
        }
    }
    if(LOW < N && arr[LOW] <= X) {
       LOW++;
    }
    return LOW;
}
void merge(int arr[], int STARTING, int MIDELEMENT, int ENDING)
{

    int len1 = MIDELEMENT - STARTING + 1;
    int len2 = ENDING - MIDELEMENT;

    int leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[STARTING + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[MIDELEMENT + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = STARTING;

    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int STARTING, int ENDING)
{
    if (STARTING < ENDING)
    {

        int MIDELEMENT = STARTING + (ENDING - STARTING) / 2;
        mergeSort(arr, STARTING, MIDELEMENT);
        mergeSort(arr, MIDELEMENT + 1, ENDING);
        merge(arr, STARTING, MIDELEMENT, ENDING);
    }
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q,arr[MAXN];
    cin>>n>>q;
    for(int i=0; i<n; i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int j=0; j<q; j++) 
    {
    int temp2;
    cin>>temp2;
    cout<<UPPER_BOUND(arr,n,temp2)-LOWER_BOUND(arr,n,temp2)<<endl;
    }
	return 0;
}