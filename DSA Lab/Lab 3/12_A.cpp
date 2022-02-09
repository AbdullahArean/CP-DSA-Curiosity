//12  aereahjh i ad     hjdsh fkshf  
#include <bits/stdc++.h>
using namespace std;

int p(char o){
    if(o == '+'||o == '-')
    return 1;
    if(o == '*'||o == '/')
    return 2;
    return 0;
}

int implement(int a, int b, char o){
    switch(o){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int evaluatefunction(string s){
    int i;

    stack <int> arr;
    stack <char> arr2;
    for(i=0; i<s.length(); i++){
        if(s[i] == ' ')
            continue;
        else if(s[i] == '('){
            arr2.push(s[i]);
        }
        else if(isdigit(s[i])){
            int val = 0;
            while(i < s.length() &&
                        isdigit(s[i])){
                val = (val*10) + (s[i]-'0');
                i++;
            }
            arr.push(val);
              i--;
        }
        else if(s[i] == ')'){
            while(!arr2.empty() && arr2.top() != '('){
                int val2 = arr.top();
               arr.pop();

                int val1 = arr.top();
                arr.pop();

                char operators = arr2.top();
                arr2.pop();

                arr.push(implement(val1, val2, operators));
            }
            if(!arr2.empty())
               arr2.pop();
        }
        else{
            while(!arr2.empty() && p(arr2.top())
                                >= p(s[i])){
                int val2 =arr.top();
                arr.pop();

                int val1 = arr.top();
                arr.pop();

                char operators = arr2.top();
                arr2.pop();

                arr.push(implement(val1, val2, operators));
            }
            arr2.push(s[i]);
        }
    }
    while(!arr2.empty()){
        int val2 = arr.top();
        arr.pop();

        int val1 = arr.top();
        arr.pop();

        char operators = arr2.top();
        arr2.pop();

        arr.push(implement(val1, val2, operators));
    }
    return arr.top();
}

int main() {
    string s;
    cin >> s;
    cout << evaluatefunction(s) << "\n";
    return 0;
}
