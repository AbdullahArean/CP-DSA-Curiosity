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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
    int tc; scanf("%d",&tc);
    for(int i=1; i<=tc; i++){
        ordered_set_pbds<pair<int, int>> st;
        cout<<"Case "<<i<<":"<<endl;
        int n,q, temp;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&temp);
            st.insert(make_pair(st.size(),temp));
    }
    getchar();
    int track = st.size();
    for(int i=1;i<=q;i++){
        char ch;
        ch=getchar();
        int x;
        if(ch=='c'){
            scanf("%d",&x); getchar();
            //cout<<ch<<" "<<x<<endl;
            if(st.size()<=x-1){
                cout<<"none"<<endl;
            }
            else{
            pair<int,int> p = *st.find_by_order(x-1);
            st.erase(p);
            cout<<p.second<<endl;
                
            }

            
        }
        else if( ch=='a'){
            scanf("%d",&x); getchar();
            //cout<<ch<<" "<<x<<endl;
            st.insert(make_pair(track++,x));
            


        }
    }

    // for(auto u:st){
    //     cout<<u.first<<" "<<u.second<<endl;
    // }

    
}
}