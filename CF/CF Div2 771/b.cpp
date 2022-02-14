/*
Problem Link  :
About Problem :
Tags          : 
 */
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+2;

void Solution(){
	int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, l,r, temp; cin>>n; 
        bool flag =1;
        int arr[MAXN],arr2[MAXN];
        for(int i=0; i<n; i++){cin>>temp;arr[i]=temp; arr2[i]=temp;}
        for(int i=0; i<n; i++)
        {
             if(arr[i]<arr[i+1] ) flag=0;
        }
        if(!flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}