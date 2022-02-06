/*
Problem Link  :
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int arr[550][550];
void prin(int n, int k)
{
	for(int j=0; j<n;j++)
		{
			for(int i=0; i<k; i++)
			{
				printf("%d ",arr[j][i]);
			}
			printf("\n");
		}

}
void matrix(int n, int k)
{
	
			int temp=1, temp2 =2;
		
		for(int j=0; j<n;j++)
		{
			for(int i=0; i<k; i++)
			{
				if(j%2==0) {arr[j][i]=temp; temp+=2;}
				else {arr[j][i]=temp2; temp2+=2;}
			}
		}

}
void Solution(){
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n, k;
		cin>>n>>k;
		if(n%2==0)
		{
			matrix(n,k);
			printf("YES\n");
			prin(n,k);

		}
		else if(k==1)
		{
			printf("YES\n");
			for(int i=1; i<=n; i++) printf("%d\n",i);
		}
		else printf("NO\n");
		
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}