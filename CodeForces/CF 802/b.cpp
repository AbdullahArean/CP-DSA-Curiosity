
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000+10000;
#define ll long long int
void Solution(){
   
  int n;
  char arr[MAXN];
   cin>>n;
   for(int i=0; i<n; i++){
    cin>>arr[i];
   }
  if(arr[0]=='9'){
    int arr2[MAXN];
    int carry=0;
    int j=0;
     if((int)(arr[n-1]-'0')>1) {arr2[j++]=11-(int)(arr[n-1]-'0');carry=1;}
    else arr2[j++]=1-(int)(arr[n-1]-'0');
    
    for(int i=n-2; i>=0;i--) 
    {
        
        int temp = (int)(arr[i]-'0');
        if(carry){
            temp+=carry; carry=0;
        }
        //cout<<"sdwfd"<<temp<<endl;
        if(temp>8){
            arr2[j++]=18-temp;
            carry=1;

        }
        else{
            arr2[j++]=8-temp;
        }

    }
    for(int i=n-1; i>=0; i--) cout<<(char)(arr2[i]+'0');

  }
  else{
    for(int i=0;i<n; i++){
        cout<<(char)(9-(int)arr[i])+'0';
    }
  }
  cout<<endl;

}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	ll testcase;
    cin>>testcase;
    while(testcase--)
    Solution();
	
	return 0;
}