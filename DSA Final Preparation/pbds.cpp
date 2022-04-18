/*
Problem Link  : 
About Problem : An awesome application of merge sort
Tags          : Merge sort inversion count 
 */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> pbds;
//We can write less_equal or graeater equal to make it multiset
const int MAXN = 1e5;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	pbds A;
    A.insert(1);
    A.insert(3);
    A.insert(14);
    A.insert(36);
    A.insert(13);
    A.insert(39);
    cout<<"PBDS A is: ";
    for(auto i: A){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"0th element "<<*A.find_by_order(0)<<endl;
    cout<<"1st element "<<*A.find_by_order(1)<<endl;
    cout<<"2nd element "<<*A.find_by_order(2)<<endl;
    cout<<endl;
    cout<<"No of element smaller than 36 or 0 based position "<<A.order_of_key(37)<<endl;
    //greater than equal 
    cout<<*A.lower_bound(35)<<endl;
    //greater 
    cout<<*A.upper_bound(35)<<endl;
    A.erase(36);
    return 0;
}