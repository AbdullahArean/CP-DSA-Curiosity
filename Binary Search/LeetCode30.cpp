
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
 vector<int> avoidFlood(vector<int> &rains)
    {
        vector<int> ans;
        set<int> s;
        int len = rains.size();
        int floodfree = 0;
        queue<int> st;
        int last=-1;
        for (int i = 0; i < len; i++)
        {
            if(rains[i]!=0){
                
                if (rains[i]!=*s.lower_bound(rains[i]))
                {
                    s.insert(rains[i]);
                }
                else
                {
                    //cout<<rains[i]<<endl;
                    st.push(rains[i]);
                }
                if(last<rains[i]) last= rains[i];
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (rains[i] != 0)
            {
                ans.push_back(-1);
            }
            else
            {
                if(st.empty()){
                    last++;
                    ans.push_back(last);

                }
                else {ans.push_back(st.front()); st.pop();}
            }
        }
        if(st.empty()) return ans;
        else {
            ans.clear();
            return ans;
        }
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> any = {1, 2, 0, 0, 2, 1};
    vector<int> ans;
    ans = avoidFlood(any);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}
// https://leetcode.com/problems/avoid-flood-in-the-city/
// class Solution
// {
// public:
//     vector<int> avoidFlood(vector<int> &rains)
//     {
//         vector<int> ans;
//         set<int> s;
//         int len = rains.size();
//         int floodfree = 0;
//         queue<int> st;
//         int last=-1;
//         for (int i = 0; i < len ; i++)
//         {
//             if(rains[i]){
//                 if(last<rains[i]) last= rains[i];
//                 if (rains[i]!=*s.lower_bound(rains[i]))
//                 {
//                     s.insert(rains[i]);
//                 }
//                 else
//                 {
//                     st.push(rains[i]);
//                 }
//             }

//         }
       
        
//         for (int i = 0; i < len; i++)
//         {
//             if (rains[i] != 0)
//             {
//                 ans.push_back(-1);
//             }
//             else
//             {
//                 if(st.empty()){
//                     last++;
//                     ans.push_back(last);

//                 }
//                 else {ans.push_back(st.front()); st.pop();}
//             }
//         }
//         if(st.empty()) return ans;
//         else {
//             ans.clear();
//             return ans;
//         }
//     }
// };