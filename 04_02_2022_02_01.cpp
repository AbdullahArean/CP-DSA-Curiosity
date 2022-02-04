/*
Author: Abdullah Ibne Hanif Arean
problem Statement: diff k
Tags: Two Pointer Approach
Reference Video: https://www.youtube.com/watch?v=ijKmiFqjzi4
*/
//Not Solved Yet!


#include<iostream>
using namespace std;
long long int factorial(int n) 
{
    if(n==0 || n==0) return 1;
    return factorial(n-1)*n;
}
 
int nCr(int n, int r) 
{
    
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int PairNumberdiff(int arr[], int n, int number)
{
    int count=0;
    for(int j=n-1, i=0;i<j;)
    {
    cout<<arr[i]<<" "<<arr[j]<<endl;
    if(abs(arr[i]-arr[j])>number) { j--;i++;}
    else if(abs(arr[i]-arr[j])<number) i++;
    else if(abs(arr[i]-arr[j])==number)
    {
        if(arr[i]==arr[j]) {
            int count1=1, pointer=i+1;
            while(arr[i]==arr[pointer]){count1++; pointer++;}
            for(int ii = 0; ii<nCr(count1,2); ii++) printf("[%d , %d]\n", arr[i], arr[j]);
            count+= nCr(count1,2); break;
            }
        else{
            int count1=1, pointer=i+1;
            while(arr[i]==arr[pointer]){count1++; pointer++;}
            int count2=1, pointer2=j-1;
            while(arr[j]==arr[pointer2]){count2++; pointer2--;}
            for(int ii = 0; ii<count2*count1; ii++) printf("[%d , %d]\n", arr[i], arr[j]);
            count+= count2 *count1;
            i+=count1;
            j-=count2;
        } 
        
    }
    	
    }
    return count;
}
int main()
{
	int n=9,k=2;
	int arr[100]= {1,4,4,5,5,5,6,6,11};
    //sort(arr, arr+n);
    cout<<PairNumberdiff(arr, n, k)<<endl;
    return 0;
}