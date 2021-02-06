#include <bits/stdc++.h>
using namespace std;

bool isInDict(string word, vector<string> dict, int dl)
{
    for (int i = 0; i < dl; i++)
    {
        if (dict[i].compare(word) == 0)
            return true;
    }
    return false;
}

void solve(string s, int n, vector<string> dict, int dl, set<string> &st, string res)
{
    for (int i = 1; i <= n; i++)
    {
        string prefix = s.substr(0, i);
        if (isInDict(prefix, dict, dl))
        {
            if (i == n)
            {
                res += prefix;
                st.insert(res);
                return;
            }
            // res = res + prefix + " ";
            // cout << "temp res = " << res << "\n";
            solve(s.substr(i, n - i), n - i, dict, dl, st, res + prefix + " ");
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int dl;
        cin >> dl;
        vector<string> dict;
        for (int i = 0; i < dl; i++)
        {
            string x;
            cin >> x;
            dict.push_back(x);
        }
        string s;
        cin >> s;
        int n = s.length();
        set<string> st;
        string res = "";
        solve(s, n, dict, dl, st, res);
        if (st.size() == 0)
            cout << "Empty";
        else
        {

            for (auto it = st.begin(); it != st.end(); it++)
            {
                cout << "(" << *it << ")";
            }
            cout << "\n";
        }
    }
}