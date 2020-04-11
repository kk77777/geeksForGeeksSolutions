#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        stack<char> s;
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            char x = str[i];
            if (s.empty())
            {
                s.push(x);
            }
            else if ((x == '}' && s.top() == '{') ||
                     (x == ')' && s.top() == '(') ||
                     (x == ']' && s.top() == '['))
            {
                s.pop();
            }
            else
            {
                s.push(x);
            }
        }
        if (s.empty())
        {
            cout << "balanced\n";
        }
        else
        {
            cout << "not balanced\n";
        }
    }
}