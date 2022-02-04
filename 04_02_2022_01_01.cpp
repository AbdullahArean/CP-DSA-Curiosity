/*
Author: Abdullah Ibne Hanif Arean
https://caring-august-d6b.notion.site/04_02_2022_01-3d5807c5f4444b6db0e57c009621ac6a
Tags: Two Pointer Approach
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	int arr[100];
	bool flag =0;
	cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
    	scanf("%d",&arr[i]);
    }
    sort(arr, arr+n);
    for(int j=n-1, i=0;i<j;){
    if(arr[i]+arr[j]==k) {flag=1; break;}
    else if((arr[i]+arr[j])<k) i++;
    	else j--;
    }
    if (flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    }
    