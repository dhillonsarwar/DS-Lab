#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int priority(char ch)
{
    if (ch == '/' || ch == '*')
        return 2;
    else
        return 1;
}

string solve(string val1, string val2, char c)
{
    string ans = "";
    ans = val1 + val2;
    ans.push_back(c);

    return ans;
}

string postfix(string &s)
{
    stack<char> op;
    stack<string> val;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch >= 48 && ch <= 57)
        {
            val.push(to_string(ch - 48));
        }
        else
        {
            if (op.empty() || priority(s[i]) > priority(op.top()))
            {
                op.push(s[i]);
            }
            else
            {
                while (!op.empty() && priority(s[i]) <= priority(op.top()))
                {
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, op.top());
                    op.pop();
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while (!op.empty())
    {
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1, val2, op.top());
        op.pop();
        val.push(ans);
    }
    return val.top();
}


int main()
{
    string cal;
    cout << "Enter an expression: " << endl;
    cin >> cal;
    string pre = postfix(cal);
    cout << "Postfix expression: " << pre << endl;
  
    return 0;
}