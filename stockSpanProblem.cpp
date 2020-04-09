#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else
        {
            while (!s.empty() && s.top().first <= a[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                v.push_back(s.top().second);
            }
            else
            {
                v.push_back(-1);
            }
        }
        s.push({a[i], i});
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << i - v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        solve(a, n);
    }
}