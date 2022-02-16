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
const long long int MAXN = 100008;
long long int LOWER_BOUND(long long int arr[], long long int N, long long int X)
{
    long long int MIDELEMENT;
    long long int LOW = 0;
    long long int HIGH = N;
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
long long int UPPER_BOUND(long long int arr[], long long int N, long long int X)
{
    long long int MIDELEMENT;
    long long int LOW = 0;
    long long int HIGH = N;
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
void merge(long long int arr[], long long int STARTING, long long int MIDELEMENT, long long int ENDING)
{

    long long int len1 = MIDELEMENT - STARTING + 1;
    long long int len2 = ENDING - MIDELEMENT;

    long long int leftArr[len1], rightArr[len2];

    for (long long int i = 0; i < len1; i++)
        leftArr[i] = arr[STARTING + i];
    for (long long int j = 0; j < len2; j++)
        rightArr[j] = arr[MIDELEMENT + 1 + j];

    long long int i, j, k;
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
void mergeSort(long long int arr[], long long int STARTING, long long int ENDING)
{
    if (STARTING < ENDING)
    {

        long long int MIDELEMENT = STARTING + (ENDING - STARTING) / 2;
        mergeSort(arr, STARTING, MIDELEMENT);
        mergeSort(arr, MIDELEMENT + 1, ENDING);
        merge(arr, STARTING, MIDELEMENT, ENDING);
    }
}
 int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long int n, q,arr[MAXN];
    cin>>n>>q;
    for(long long int i=0; i<n; i++) cin>>arr[i];
    mergeSort(arr,0,n-1);

    for(long long int j=0; j<q; j++) 
    {
    long long int temp2;
    cin>>temp2;
    cout<<UPPER_BOUND(arr,n,temp2)-LOWER_BOUND(arr,n,temp2)<<endl;
    }
	return 0;
}