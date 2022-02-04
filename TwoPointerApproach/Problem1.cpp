/*
Author: Abdullah Ibne Hanif Arean
Concept: Two Pointer
        Links: https://www.geeksforgeeks.org/two-pointers-technique/
Problem Statement: Find the closest pair from two sorted arrays
        Links: https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/
Tags: Two Pointer
*/
#include<bits/stdc++.h>
using namespace std;
void printClosest(int arr1[], int arr2[],int m, int n, int x){
    int p1, p2;
    int temp;
    for(int i=0,j=n-1;i<m && j>=0;)
    {
        if(i==0 && j==n-1) {temp = arr1[i]+arr2[j]; p1= arr1[i]; p2=arr2[j];}
        if((arr1[i]+arr2[j])==x) {temp = arr1[i]+arr2[j]; p1= arr1[i]; p2=arr2[j]; break;}
        else if((arr1[i]+arr2[j])<x){
            if(abs(temp-x)>abs((arr1[i]+arr2[j])-x)){
                temp = arr1[i]+arr2[j]; 
                p1= arr1[i]; 
                p2=arr2[j];}
                i++;

        }
        else if((arr1[i]+arr2[j])>x){
             if(abs(temp-x)>abs((arr1[i]+arr2[j])-x)){
                temp = arr1[i]+arr2[j]; 
                p1= arr1[i]; 
                p2=arr2[j];}
                j--;
                

        }


    }
    printf("The closest pair is [%d , %d]\n", p1, p2);

}
int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 38;
    printClosest(ar1, ar2, m, n, x);
    return 0;
}