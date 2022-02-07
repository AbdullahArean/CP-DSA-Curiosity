/*
Problem Link  :
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

void Solution(){
	int testcase;
	cin>>testcase;
	while(testcase--){
		string s;
		cin>>s;
		int onec=0, zeroc=0;
		int len = s.size();
		for(int i=0; i<len; i++){
			if(s[i]=='1') onec++;
			else zeroc++;
		}
		if(len<3) printf("0\n");
		else if(onec==zeroc) printf("%d\n",zeroc-1);
		else{
			(onec<zeroc)?printf("%d\n",onec):printf("%d\n",zeroc);
		}

	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}