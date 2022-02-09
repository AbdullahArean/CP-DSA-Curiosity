//12
//12
//12
//12
//12
//12
//12
//12
#include <stdio.h>
#define Maxx 100000

using namespace std;
long int bs(char arr[], int n, int p)
{
    //printf("%c %c %c\n",arr[n-p],arr[p-1],(arr[n-p]!=arr[p-1]));
    if(p<=n/2) return 0;
    return (arr[n-p]!=arr[p-1])+ bs(arr,n,p-1);
}


int main()
{
    int arr[2001];
    char bnum[20001];
    for (int i = 0; i < 2001; i++)
    {
        bnum[i] = 10;
    }
    scanf("%s", bnum);
    int i = 0;
    for (i = 0;bnum[i]!=10; i++)
    {
        arr[i] = bnum[i] - '0';
    }
    i--;
    //printf("%d\n",i);
    if(bs(bnum,i,i)==0) printf("Palindrome\n");
    else printf("Not Palindrome\n");

    return 0;
}