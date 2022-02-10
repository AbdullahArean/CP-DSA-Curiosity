/*
Problem Link  : https://onlinejudge.org/external/120/12032.pdf
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int Ans
void Solution(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int t, arr[MAXN], mindiff=0, diff;
		cin>>t;
		for(int i=0; i<t; i++) 
		{
			cin>>arr[i];
			if(i==0) mindiff=arr[0];
			else {
				diff = arr[i]-arr[i-1];
				if(diff>mindiff) mindiff=diff; 
			}
		}
		
		printf("Case %d: %d\n", i+1,mindiff);
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}