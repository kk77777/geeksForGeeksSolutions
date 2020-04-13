#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        unordered_map<int, int> p;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            p[a[i]]++;
        }

        vector<pair<int, int>> v;
        copy(p.begin(), p.end(), back_inserter(v));
        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < v.size(); ++i)
            for (int j = 0; j < v[i].second; ++j)
                cout << v[i].first << " ";
        cout << "\n";
    }
}