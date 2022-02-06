/*
Problem Link  : https://codeforces.com/contest/1632/problem/B
About Problem : Bit Manipulation Game
Tags          : bits, easy, greedy
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

// void decToBinary(int n)
// {
//     // array to store binary number
//     int binaryNum[32];
 
//     // counter for binary array
//     int i = 0;
//     while (n > 0) {
 
//         // storing remainder in binary array
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }
 
//     // printing binary array in reverse order
//     for (int j = i - 1; j >= 0; j--)
//         cout << binaryNum[j];
// }
void Solution(int n){
	
	for(int i=0;i<n; i++)
	{
		int t;
		cin>>t;
		int p=0;
		while(t/pow(2,p)>1) p++;
		p= pow(2,p-1);
		for(int i=1;i<p; i++) {printf("%d ",i);}
		printf("0 ");
		for(int i=p; i<t; i++) {printf("%d ",i);}
		printf("\n");
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin>>n;
	Solution(n);
	
	return 0;
}