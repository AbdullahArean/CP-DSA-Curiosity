#include<bits/stdc++.h>
using namespace std;

long long int bigmod(long long a, long long p,long long int m)
{
	if(p==0) return 1;
	if(p%2)// if power is odd
	{
		return ( (a%m) * (bigmod(a,p-1,m)) )%m;
	} 
	else
	{
		long long c= bigmod(a, p/2 , m);
		return ( (c%m)*(c%m))%m;
	}
} 

int main()
{

}