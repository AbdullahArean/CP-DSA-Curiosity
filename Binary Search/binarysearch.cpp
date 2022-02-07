/*
Problem Link  :
About Problem : Binary Search Implementation
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
void printarray(int arr[],int low, int high){
    for(int i=low; i<=high; i++) printf("%d ",arr[i]);
    printf("\n");
}
int BinarySearch(int arr[], int N, int value){
    int low = 0,high = N-1, mid;

    while(low<=high){
        printarray(arr,low,high);
        mid = (high+low)/2;
        if(arr[mid]>value) high=mid-1;
        else if( arr[mid]<value) low = mid+1;
        else return mid;
        
    }
    return low;//lower Bound returning

}
void Solution(){
    int arr[] = {2, 5, 23, 45, 78, 345, 768, 987, 1098, 1099};
    int N= 10;
    
    cout<<arr[BinarySearch(arr,N,7)];
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}