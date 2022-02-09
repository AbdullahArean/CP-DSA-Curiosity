//12
//12
//12

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define ll long long int 

double sqrtbinarysearch(double n)
{
	double l = 0, h = n , midele;

	while(l <= h)
	{
    	midele  = (l+h)/2;
    	if(abs(midele*midele - n) < 10E-7)
        	return midele;
    	else if(midele * midele < n)
        	l = midele;
    	else if(midele*midele > n)
        	h = midele;
	}
	return midele;
}


void Solution()
{
	double input;
	int testcase;
	cin>>testcase;
	for(int i = 0; i<testcase ;i++)
	{
   	 cin>>input;
    printf("%lf\n",sqrtbinarysearch(input));
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}

