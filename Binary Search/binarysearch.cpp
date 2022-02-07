/*
Problem Link  : Binary Search, Lower Bound and Upper Bound Implemented and matched with STL
About Problem : Binary Search Implementation
Tags          : 
Notes         :
        lower_bound returns an iterator pointing to the first element 
        in the range [first,last) which has a value not less than ‘val’. 
        upper_bound returns an iterator pointing to the first element in the 
        range [first,last) which has a value greater than ‘val’. 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
void printarray(int arr[],int low, int high){
    for(int i=low; i<=high; i++) printf("%d ",arr[i]);
    printf("\n");
}
int BSUpperBound(int arr[], int N, int value) {
    int low = 0,high = N-1, mid;
    while (low < high) {
        //printarray(arr,low,high);
        mid = low+ (high-low)/2;
        if(arr[mid]>value)  high = mid;
        else low= mid+1;
    }
    if(value>=arr[N-1]) low++; //To match built in functions
    return low;
}
int BSLowerBound(int arr[], int N, int value) {
     int low = 0,high = N-1, mid;
    while (low < high) {
        //printarray(arr,low,high);
        mid = low+ (high-low)/2;
        if(arr[mid]>=value) {
            high = mid;
        } 
        else {
            low= mid+1;
        }
    }
    if(value>=arr[N-1]) low++; //To match built in functions
    return low;
}
int BinarySearch(int arr[], int N, int value){
   
    int low = 0,high = N-1, mid;
    while(low<=high){ //Equal Sign is a must or else false result!
        //printarray(arr,low,high);
        mid = (high+low)/2;
        if(arr[mid]>value) high=mid-1;
        else if( arr[mid]<value) low = mid+1;
        else return 1;
    }
    return -1;

}
void Solution(){
    int arr[] = {2, 5,5,5,5,5 ,23, 45, 78, 345, 768, 987, 1098, 1099};
    int N= 14;
    
    //cout<<BSLowerBound(arr,N,3);
    for(int i=0; i<N; i++){
        cout<<lower_bound(arr,arr+N,arr[i]+1)-arr<<" Lower Bound "<<BSLowerBound(arr,N,arr[i]+1)<<endl;

        cout<<upper_bound(arr,arr+N,arr[i]+1)-arr<<" Upper Bound "<<BSUpperBound(arr,N,arr[i]+1)<<endl;
    }
    	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}