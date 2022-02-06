/*
Problem Link  :
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
bool check(string s){
	int len = s.size();
	for(int i=0; i<len/2; i++)
	{
		if(s[i]!=s[len-i-1]) return 1;
	}
	return 0;
}
void Solution(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		
		if(b<2) cout<<"1\n";
		else if(!check(s)) cout<<"1\n";
		else cout<<"2\n";


	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}