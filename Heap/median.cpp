#include<bits/stdc++.h>
using namespace std;
/*
class MedianFinder {
    priority_queue<int> maxhp;
    priority_queue<int, vector<int>, greater<int>> minhp;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxhp.empty() || maxhp.top() >= num) {
            maxhp.push(num);
        } else {
            minhp.push(num);
        }
        
        if(maxhp.size() > minhp.size() + 1) {
            minhp.push(maxhp.top());
            maxhp.pop();
        } else if(maxhp.size() < minhp.size()) {
            maxhp.push(minhp.top());
            minhp.pop();
        }
    }
    
    double findMedian() {
        if(maxhp.size() == minhp.size()) {
            return (maxhp.top() + minhp.top()) / 2.0;
        } else  {
            return maxhp.top();
        }
    }
};
*/
priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;
void insert(int x){
    if(pqmin.size()== pqmax.size()){
        if(pqmax.size()==0){
            pqmax.push(x); 
            return;
        }
        if(x<pqmax.top()) pqmax.push(x);
        else pqmin.push(x);
    }
    else{
        if(pqmax.size()<pqmin.size()){
            if(x<pqmax.top()) pqmax.push(x);
            else{
                pqmax.push(pqmin.top());
                pqmin.top();
                pqmin.push(x);

            }

        }
        else if(pqmax.size()>pqmin.size()){
            if(x<pqmax.top()){
                pqmin.push(pqmax.top());
                pqmax.pop();
                pqmax.push(x);
            }
            else pqmin.push(x);

        }
    }
}
double findMedian(){
    if(pqmax.size()==pqmin.size()) return (double)(pqmax.top()+pqmin.top())/2.00;
    else if(pqmax.size()>pqmin.size()) return pqmax.top();
    return pqmin.top();
}
int main(){

return 0;
}