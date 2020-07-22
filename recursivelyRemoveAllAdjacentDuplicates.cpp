#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    if (s.empty())
        return "";
    int n = s.length();
    stack<char> st;
    bool flag = 0, key = 0;
    for (int i = 0; i < n; i++)
    {
        st.push(s[i]);
    }
    s = "";
    char c = st.top();
    st.pop();
    while (!st.empty())
    {
        if (st.top() == c)
        {
            flag = 1;
            key = 1;
        }
        else
        {
            if (!flag)
                s += c;
            flag = 0;
            c = st.top();
        }
        st.pop();
    }

    if (!flag)
    {
        s += c;
    }
    reverse(s.begin(), s.end());
    if (key)
    {
        s = solve(s);
    }
    return s;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
}