/*
Problem Link  :
About Problem :
Tags          : 
 */
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

void Solution(){
	int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int n, count=0; cin>>n; 
        int arr[MAXN];
        for(int p=0; p<n; p++)cin>>arr[p];
        for(int i=0; i<n; i++)
        {
            if(arr[i]>i) count++;
        }
        cout<<count<<endl;

    }

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}