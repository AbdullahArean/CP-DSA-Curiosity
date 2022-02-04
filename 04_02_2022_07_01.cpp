/*
Author:Abdullah Ibne Hanif Arean
Problem: maximus contiguous 1(last Problem of scaler two pointer)
Link:https://www.interviewbit.com/problems/max-continuous-series-of-1s/
//Not Solved Yet
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> maxone(vector<int> &A, int B) {
    int n = A.size();
    int st = 0, end=0;
    int ans_st =0, ans_end=0;
    int flips =0;
    while(end<n-1){
        //Window Expansion
        while (end<n && flips<=B)
        {
            if(A[end]==0) flips++;
            if(flips<=B and end-st>ans_end-ans_st){
                ans_st = st; ans_end= end;
            }
            end++;
        }
        //window contraction
        while(st<end and flips>B){
            if(A[st]==0) flips--;
            st++;
        }
        
    }
    vector<int>ans={};
    for(int i= ans_st; i<=ans_end; i++) {ans.push_back(i);cout<<ans[i]<<endl;}
    return ans;
}

vector<int> f1(vector<int>a, int B){
    int n = a.size();
    int st = 0, end=0;
    int ans_st =0, ans_end=0;
    int flips =0;
    while(end<n-1){
        //Window Expansion
        while (end<n && flips<=B)
        {
            if(a[end]==0) flips++;
            if(flips<=B and end-st>ans_end-ans_st){
                ans_st = st; ans_end= end;
            }
            end++;
        }
        //window contraction
        while(st<end and flips>B){
            if(a[st]==0) flips--;
            st++;
        }
        
    }
    vector<int>ans={};
    for(int i= ans_st; i<=ans_end; i++) {ans.push_back(i);cout<<ans[i]<<endl;}
    return ans;

}

int main(){
    vector<int>a ={0, 1, 1, 1 };
    int M= 0;
    maxone(a,M);


}