/*
Author: Abdullah Ibne Hanif Arean
Problem Statement:
https://caring-august-d6b.notion.site/04_02_2022_01-3d5807c5f4444b6db0e57c009621ac6a
Tags: Naive Approach, Two Pointer Approach
Reference Video: https://www.youtube.com/watch?v=ijKmiFqjzi4
*/

/*****************
//Next task is to print which positions make pair?
//Learn it through hashmapping
//finish video of two pointer https://www.youtube.com/watch?v=ijKmiFqjzi4
//start josepus problem and recurion and finish before night 10 PM 
    Links:
            https://youtube.com/playlist?list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9
            https://www.youtube.com/playlist?list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY
            https://www.youtube.com/playlist?list=PL9gnSGHSqcnp39cTyB1dTZ2pJ04Xmdrod
******************/

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

bool isPairSum(int A[], int N, int X)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // as equal i and j means same element
            if (i == j)
                continue;
 
            // pair exists
            if (A[i] + A[j] == X)
                return true;
 
            // as the array is sorted
            if (A[i] + A[j] > X)
                break;
        }
    }
 
    // No pair found with given sum.
    return false;
}
bool isPairSumTwoPointer(int arr[], int n, int k)
{
    bool flag =0;
    for(int j=n-1, i=0;i<j;){
    if(arr[i]+arr[j]==k) {flag=1; break;}
    else if((arr[i]+arr[j])<k) i++;
    	else j--;
    }
    return flag;
}
//Most Complex One 
//Takes input of any kind of sorted array its number and another number
//Givees output of how many pair it can have making number given
int PairNumber(int arr[], int n, int number)
{
    int count=0;
    for(int j=n-1, i=0;i<j;)
    {
    if((arr[i]+arr[j])>number) { j--;}
    else if((arr[i]+arr[j])<number) i++;
    else if((arr[i]+arr[j])==number)
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
	int n=9,k=10;
	int arr[100]= {1,4,4,5,5,5,6,6,11};
    //sort(arr, arr+n);
    cout<<PairNumber(arr, n, k)<<endl;
    return 0;
}