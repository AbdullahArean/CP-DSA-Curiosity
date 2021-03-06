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

void Solution(){
	int n;
	cin>>n;
	for(int i=0 ; i<n; i++){
		
		printf("Case %d:\n", i+1);
	}
	
	
}
bool checkithbitsetornot(int n, int i){
    int mask = 1;
    mask =1<<i;
    return n&mask;
}
int countingsetbits(int n){
    int count =0;
    while(n>0){
        if((n&1)>0) count++;
        n= n>>1;
    }
    return count;

}
int countingsetbits2(int n){
    int count=0;
    while(n>0){
        count++;
        n= n & (n-1);
    }
    return count;
}
bool checkifpoweroftwo(int n){
    if(n<=0) return false;
    else if((n & (n-1))==0) return true;
    else return false;

}
/*
Important Notes on XOR :
A^A = 0;
0^A = A;
Ordering of XOR doesn't matter: 2^3^7 =  (2^3)^7 = 2^(3^7);
*/
void XORQueries(){
    int n, temp, m;
    cin>>n>>m;
    int arr[MAXN],pre[MAXN];
    for(int i=0; i<n; i++) cin>>arr[i];
    pre[0]= arr[0];
    for(int i=0; i<n; i++){
        pre[i]=pre[i-1]^arr[i];
       //cout<<pre[i]<<arr[i]<<endl;
    }
    for(int i=0; i<m; i++){
        int l,r;
        cin>>l>>r;
        if(l==0) cout<<pre[r]<<endl;
        else cout<<(pre[r]^pre[l-1])<<endl;

    }

}
int allpairsum(int arr[], int n){
    int ans=0;
    for(int i=0; i<n; i++){
        ans=ans^(2*i);
    }
    return ans;


}
int xorarray(int arr[], int n){
    int ans=0;
    for(int i=0; i<n;i++){
        ans=ans^arr[i];
    }
    return ans;

}// Function to set the kth bit of n
int setBit(int n, int k)
{
    return (n | (1 << (k - 1)));
}
  
// Function to clear the kth bit of n
int clearBit(int n, int k)
{
    return (n & (~(1 << (k - 1))));
}
  
// Function to toggle the kth bit of n
int toggleBit(int n, int k)
{
    return (n ^ (1 << (k - 1)));
}
int unxor(int a, int resxor){
    int ans =0;
    int i=0;
    while(resxor>0){
        if((resxor&1)>0) {
            if((a&1)>0){
                clearBit(ans,i);
            }
            else{
                setBit(ans,i);
            }
        }
        resxor= resxor>>1;
        a=a>>1;
        i++;
    }
    cout<<ans;

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	// cout<<checkithbitsetornot(3,0)<<endl;
	// cout<<countingsetbits(3)<<endl;
    // cout<<countingsetbits2(3)<<endl;
    // cout<<checkifpoweroftwo(15)<<endl;
    //XORQueries();
    // int arr[]={1,2,3};
    cout<<unxor(2,1);
    return 0;
}