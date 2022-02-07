/*
Problem Link  :
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
bool isPrime(int N){
    if(N==1) return false;
    for(int i=2; i*i<N; i++){
        if(N%i==0) return false;

    }
    return true;
}
void Solution(){
    cout<<isPrime(23)<<endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}