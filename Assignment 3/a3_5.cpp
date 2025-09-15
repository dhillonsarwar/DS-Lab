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
int sol(int val1, int val2, char c)
{
    if (c == '/')
    {
        return val1 / val2;
    }
    if (c == '*')
    {
        return val1 * val2;
    }
    if (c == '+')
    {
        return val1 + val2;
    }
    if (c == '-')
    {
        return val1 - val2;
    }
    return -1;
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

int calculate(string &s)
{
    string post = postfix(s);
    stack<int> result;
    for (int i = 0; i < post.size(); i++)
    {
        if (post[i] >= 48 && post[i] <= 57)
        {
            result.push(post[i] - 48);
        }
        else
        {
            char c = post[i];
            int val2 = result.top();
            result.pop();
            int val1 = result.top();
            result.pop();
            int ans = sol(val1, val2, c);
            result.push(ans);
        }
    }
    return result.top();
}
int main()
{
    string cal;
    cout << "Enter an expression: " << endl;
    cin >> cal;
    string pre = postfix(cal);
    cout << "Postfix expression: " << pre << endl;
    int result = calculate(cal);
    cout << "Result: " << result<<endl;

    return 0;
}