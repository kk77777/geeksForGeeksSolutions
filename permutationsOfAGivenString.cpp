#include <bits/stdc++.h>
using namespace std;

void solve(string s, int l, int r, set<string> &st)
{
    if (l >= r)
    {
        st.insert(s);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            solve(s, l + 1, r, st);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        set<string> st;
        // sort(s.begin(), s.end());
        solve(s, 0, s.length() - 1, st);
        for (auto it = st.begin(); it != st.end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
}