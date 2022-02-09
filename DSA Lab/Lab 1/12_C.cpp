//12
//12
//12
//12
#include<stdio.h>

long long int gcdusingrecursion(int a, int b)
{
    
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    
    if (a == b)
        return a;
  
   
    if (a > b)
        return gcdusingrecursion(a-b, b);
    return gcdusingrecursion(a, b-a);
}
int main()
{
    long long int a, b;
    scanf("%lld %lld",&a,&b);
    if(b>a) {long long int temp=a; a=b; b=temp;}
    printf("%lld\n",gcdusingrecursion(a,b));

}