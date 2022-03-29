#include <bits/stdc++.h>
using namespace std;
#define DIV " "
int check_priority(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '/' || ch == '*')
        return 3;
    else if (ch == '-')
        return 2;
    else if (ch == '+')
        return 1;
    else
        return -1;
}

void infToPost(string infix)
{
    stack<char> stack1;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (ch >= '0' && ch <= '9')
        {
            postfix += ch;
            if (i != infix.length() - 1 && (infix[i + 1] >= '0' && infix[i + 1] <= '9'))
                continue;
            postfix += DIV;
        }
        else if (ch == '(')
            stack1.push('(');
        else if (ch == ')')
        {
            while (stack1.top() != '(')
            {
                postfix += stack1.top();
                postfix += DIV;
                stack1.pop();
            }
            stack1.pop();
        }
        else
        {
            while (!stack1.empty() && check_priority(infix[i]) <= check_priority(stack1.top()))
            {
                postfix += stack1.top();
                postfix += DIV;
                stack1.pop();
            }
            stack1.push(ch);
        }
    }
    while (!stack1.empty())
    {
        postfix += stack1.top();
        postfix += DIV;
        stack1.pop();
    }

    postfix.pop_back();

    cout << postfix << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("inp.txt","r",stdin); freopen("output.txt","w",stdout);

    string infix;
    cin >> infix;
    infToPost(infix);
    return 0;
}