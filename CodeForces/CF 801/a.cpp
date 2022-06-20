/*
Problem Link  : 
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

 
void Solution() {
    long long int n,m;
    cin >> n >> m;
    long long int ans = (m*(m+1))/2 +m*(n-1)+(n*m*(n-1))/2;



    cout <<ans<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int testcase;
    cin>>testcase;
    while(testcase--)
    Solution();
	
	return 0;
}

    // int arr2[MAXN];
    // int carry=0;
    // if((int)arr[n-1]>1) {arr2[0]=11-(int)arr[n-1];carry=1;}
    // else arr2[0]=1-(int)arr[n-1];
    // int j=1;
    // for(int i=n-2; i>=0;i--) 
    // {
    //     int temp = (int)arr[i];
    //     if(carry){
    //         temp+=carry; carry=0;
    //     }
    //     if(temp>8){
    //         arr2[j++]=18-temp;
    //         carry=1;

    //     }
    //     else{
    //         arr2[j++]=8-temp;
    //     }

    // }
    // for(int i=n-1; i>=0; i--) cout<<arr2[i];






    // arr[n]='\0';
    // ll num;
    // sscanf(arr, "%d", &num);
    // cout<<generate(num);

  }