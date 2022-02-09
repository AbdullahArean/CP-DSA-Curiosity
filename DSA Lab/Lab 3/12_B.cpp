//12
//12
//12
#include <iostream>
using namespace std;
#define ll int
int function(ll numberofpeople, ll stepnumber) {
    ll safe = 0;
    for (int i = 2; i <= numberofpeople; i++)
        safe = (safe + stepnumber) % i;

    return safe;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
      ll numberofpeople, stepnumber;
    scanf("%d %d", &numberofpeople, &stepnumber);
    cout<<function(numberofpeople,stepnumber)+1<<endl;
}