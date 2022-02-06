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
	while(n--)
	{
		bool flag =0; //alice 0 bob 1
		int n, x, y;
		vector<int>v;
		cin>>n>>x>>y;
		for(int i=0; i<n; i++) {int temp; cin>>temp; v.push_back(temp);}
		//Checking if alice
		for(int i=0; i<n;i++){
			

		}
		if(flag) printf("Bob\n");
		else printf("Alice\n");
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}