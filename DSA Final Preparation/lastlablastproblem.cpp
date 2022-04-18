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

//We can write less_equal or graeater equal to make it multiset
template <class T>
using ordered_set_pbds = tree<T,null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 1e5 + 3;
const int MAXN = 1429431 + 20;

int ans[MAX];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	ordered_set_pbds<int> st;
       st.insert(0);

    for (int i = 1; i < MAXN; i += 2) st.insert(i);

    ans[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (st.size() <= i) break;
        int x = *(st.find_by_order(i));

        vector <int> v;
        for (int j = x; j < MAXN; j += x) {
            if (j >= st.size()) break;
            v.push_back(*st.find_by_order(j));
        }

        for (int mul : v) st.erase(mul);

        ans[i] = x;
    }

    int tc; scanf("%d",&tc);
    int kase=0;
    while(tc--){
        printf("Case %d: ",++kase);
        int n; scanf("%d",&n);
        printf("%d\n" ,ans[n]);

    }
    
}