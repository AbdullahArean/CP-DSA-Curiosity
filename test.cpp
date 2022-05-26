/*
Problem Link  : 
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define DIV ' '
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

int Precedence(char given){
	switch (given)
	{
	case '*':
		return 2;
		break;
	
	case '/':
		return 2;
		break;
	
	case '-':
		return 1;
		break;
	
	case '+':
		return 1;
		break;
	
	default:
		return -1;
		break;
	}
	
}
string infixtopostfix(string infix){
	stack<char> s;
	string ans = "";
	for(int p=0; p<infix.length(); p++){
		char i= infix[p];
		if(isalnum(i)) {
			ans= ans +i;
            if (i != infix.length() - 1 && (isalnum(infix[p+ 1])))
                continue;
            ans += DIV;
        }
		else if( i=='(') s.push(i);
		else if(i==')'){
			while(s.top()!='('){
				ans+=s.top();
				ans += DIV;
				s.pop();
			}
			s.pop();

		}
		else if(Precedence(i)>=1){
			if(s.empty() || Precedence(i)>Precedence(s.top())||s.top()=='(') 
			{s.push(i);}

			else{
				while(Precedence(i)<Precedence(s.top())){
					ans+=s.top();
					ans += DIV;
					s.pop();
				}
				ans+=i;
				ans += DIV;

		 }

		}
	 }
	 while(!s.empty()){
		 ans+=s.top();
		 ans += DIV;
		 s.pop();
	 }
	//cout<<ans<<endl;
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string inf ="3+(2*(7-2)*5-2)*3";
    cout<<infixtopostfix(inf);
	
	return 0;
}