//12
//12
//12
//12
//12
#include <stdio.h>
#define Maxx 100000

using namespace std;
long int bs(int arr[], int p)
{
    if(p==0) return 0;
    return 2*bs(arr,p-1)+arr[p-1];
}

int main()
{
    int arr[100];
    char bnum[100];
     for (int i = 0; i < 100 ; i++ ) 
   {
      bnum[i]=10;
   }
    scanf("%s",bnum);
    int i=0;
    for(i=0;bnum[i]=='0' || bnum[i]=='1' ; i++)
    {
        arr[i]=bnum[i]-'0';
    }
    
    printf("%ld\n",bs(arr,i));
    
    return 0;
}