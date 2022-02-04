/*
Author: Abdullah Ibne Hanif Arean
problem Statement: Getting the minimum value of absolute difference of max(a, b, c) and min(a,b,c) where a belongs
                to sorted list A, b to B, and c to C
Tags: Two Pointer Approach
Reference Video: https://www.youtube.com/watch?v=ijKmiFqjzi4 (Problem 2)
*/
//Not Solved Yet!
#include<iostream>
using namespace std;
int bruteforce(int A[], int B[], int C[], int l1, int l2, int l3){
    int ans;
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            for (int k = 0; k < l3; k++)
            {
                
                int temp = abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k])));
                
                if(i==0 && j==0 && k==0) ans= temp;
                
                if(temp<ans) ans= temp;
                cout<<A[i]<<" "<<B[j]<<" "<<C[k]<<" max "<<max(A[i],max(B[j],C[k]))<<" min "<<min(A[i],min(B[j],C[k]))<<" diff "<<temp<<" Ans "<<ans<<endl;
            }
            
        }
        
    
    }
    return ans;
    
}
int f1(int A[], int B[], int C[], int l1, int l2, int l3)
{
    int ans=0;
    for(int ap=0,bp=0,cp=0;ap<l1,bp<l2,cp<l3;)
    {
        int temp = abs(max(A[ap],max(B[bp],C[cp]))-min(A[ap],min(B[bp],C[cp])));
        if(ap==0 && bp==0 && cp==0) ans= temp;
        if(temp<ans) ans= temp;
        cout<<A[ap]<<" "<<B[bp]<<" "<<C[cp]<<" max "<<max(A[ap],max(B[bp],C[cp]))<<" min "<<min(A[ap],min(B[bp],C[cp]))<<" diff "<<temp<<" Ans "<<ans<<endl;
            

        //logical increament
        if(A[ap]<=B[bp] && A[ap]<=C[cp]) ap++;
        if(A[ap]<=B[bp] && A[ap]<=C[cp]) ap++;
        if(A[ap]<=B[bp] && A[ap]<=C[cp]) cp++;
    }
    return ans;
}
int main()
{
    int A[] = {1, 4, 5,8,10};
    int B[] = {6, 9,15};
    int C[] = {2, 3,6,6};
    cout<<f1(A,B,C,5,3,4)<<endl;
    return 0;
}
