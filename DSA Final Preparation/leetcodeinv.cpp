/*
Problem Link  : https://leetcode.com/problems/global-and-local-inversions/submissions/
About Problem : An awesome application of merge sort
Tags          : Merge sort inversion count 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long int merge(vector<int>& nums, int start, int mid, int end)
{
    long long int inv=0;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int leftnums[len1], rightnums[len2];

    for (int i = 0; i < len1; i++)
        leftnums[i] = nums[start + i];
    for (int j = 0; j < len2; j++)
        rightnums[j] = nums[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (leftnums[i] <= rightnums[j])
        {
            nums[k] = leftnums[i];
            i++;
        }
        else
        {
            nums[k] = rightnums[j];
            inv+=len1-i;
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        nums[k] = leftnums[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        nums[k] = rightnums[j];
        j++;
        k++;
    }
    return inv;
}
long long int mergeSort(vector<int>& nums, int start, int end)
{
    long long int inv =0;
    if (start < end)
    {

        int mid = start + (end - start) / 2;
        inv+=mergeSort(nums, start, mid);
        inv+=mergeSort(nums, mid + 1, end);
        inv+=merge(nums, start, mid, end);
    }
    return inv;
}
public:
    bool isIdealPermutation0(vector<int>& nums) {
    long long int localinv=0;
	for(int i=0 ; i<nums.size(); i++){
        if(i>0 && nums[i-1]>nums[i]) localinv++; 
	}
    long long int globalinv=mergeSort(nums,0,nums.size()-1);
    if(globalinv==localinv) return true;
    else return false;
        
    }
        bool isIdealPermutation(vector<int>& nums) {   int n = nums.size(), i;
    
    for(i=0; i < n; i++)
    {
        if(abs(nums[i]- i) > 1)
        {
            return false;
        }
    }
    
    return true;
    
}
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        int minNum[n];
        minNum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            minNum[i]=min(minNum[i+1],nums[i]);
        }
        
        for(int i=0;i+2<n;i++){
            if(nums[i] > minNum[i+2])return false;
        }
        return true;
    }
};