#include<bits/stdc++.h>
using namespace std;
int maxarea(int arr[], int n){
    int area = 0;
    int st = 0;
    int end = n-1;
    while(st<end){
        int curarea= min(arr[st], arr[end])*(end-st);
        //printf("%d %d forms height %d length %d Area %d Max Area %d\n",arr[st], arr[end],min(arr[st], arr[end]),(end-st),curarea,area );
        area = max(area, curarea);
        if(arr[st]< arr[end]) st++;
        else end--;
    }
    return area;

}
int main()
{
    int arr[]= {7,8,6,6,2,5,4,8,3,7};
    cout<<maxarea(arr,10)<<endl;

}