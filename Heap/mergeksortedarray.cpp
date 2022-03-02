/*
Problem Link  : 
About Problem :
Tags          : 
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
vector<int> Solution(vector<vector<int> > &A) {
    priority_queue<int, vector<int>, greater<int>> p;
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[i].size(); j++){
            p.push(A[i][j]);
        }
    }
    
    vector<int> res;
    while(!p.empty()){
        res.push_back(p.top());
        p.pop();
    }
    
    return res;
}
	

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> A;
    A = {{1, 2, 3},
        {2, 4, 6},
        {0, 9, 10}
    };
	vector<int> res = Solution(A);
    int i=0;
    while(i<res.size()){
        cout<<res[i++]<<endl;

    }
	
	return 0;
}