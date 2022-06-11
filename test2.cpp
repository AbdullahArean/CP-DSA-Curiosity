#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> anslist;
        int mpro = 0;
        int ansfinal=0;
        deque<int> container;
        int len = prices.size();
        for(int i=0; i<len; i++){
            if(container.empty()) container.push_front(prices[i]);
            else if(container.front()<=prices[i]) container.push_front(prices[i]);
            else{
                int ans = container.front()-container.back();
                ansfinal+=ans;
                anslist.push_back(ans);
                if(mpro<ans) mpro=ans;
                while(container.front()>prices[i]) container.pop_front();
                // container.pop_back();
                container.clear();
                container.push_front(prices[i]);
            } 
        }
        if(!container.empty()){
        int ans = container.front()-container.back();
        if(mpro<ans) mpro=ans;
        ansfinal+=ans;
        anslist.push_back(ans);
        
        }
        sort(anslist.begin(), anslist.end());
        if(anslist.empty()) return 0;
        else if (anslist.size()==1) return anslist[0];
        else return anslist[0]+anslist[1];
        
    }
};

