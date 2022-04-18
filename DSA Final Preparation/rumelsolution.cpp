#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // scanf("%d\n",&t);
    cin >> t;
    for(int i = 1; i <= t ; i++){
        string s;
        getline(cin,s);
        int n,q;
        // scanf("%d %d\n",&n,&q);
        cin >> n >> q;
        vector<int>v;
        for(int j = 0 ; j < n ; j++){
            int in;
            cin >> in;
            // scanf("%d ",&in);
            v.push_back(in);
        }
        cout<<"Case "<<i<<":\n";
        while(q--){
            char c;
            int in ;
            cin >> c >> in ;
            // scanf("%c %d\n",&c,&in);
            if(c =='c'){
                int flag = 0;
                auto it = v.begin();
                if(in <= v.size()){
                    cout<<*(it+in-1)<<endl;
                    v.erase(it+in-1);
                    flag = 1;
                }
               
                if(!flag)
                cout<<"none"<<endl;
            }else{
                v.push_back(in);
            }
        }
       
    }
}