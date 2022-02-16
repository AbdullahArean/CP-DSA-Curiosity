//12
//12
//12
//12
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
void Solution(){
	int n,q, sum=0;
    map<string, int> m1;
	cin>>n>>q;
    while(n--)
    {
        string s; int price;
        cin>>s>>price;
        m1[s]=price;

    }
    while(q--){
        string s;
        cin>>s;
        sum+=m1[s];

    }
    printf("%d\n", sum);
	
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solution();
	
	return 0;
}