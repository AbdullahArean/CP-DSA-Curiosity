/*
Eucledian algorithm for gcd lcd using modulo
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a>b){
        if(b==0) return a;
    else return gcd(b, a%b);
    }
    else{
        if(a==0) return b;
        else return gcd(a, b%a);
    }
    
}
int lcd(int a, int b){
    return (a*b)/gcd(a,b);

}
int main(){
    int a=8;
    int b =12;
    cout<<gcd(a,b)<<endl;
    cout<<lcd(a,b)<<endl;
}