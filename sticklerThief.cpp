#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int t[n];
        t[0] = v[0];
        t[1] = max(v[0], v[1]);
        for (int i = 2; i < n; i++)
        {
            t[i] = max(v[i] + t[i - 2], t[i - 1]);
        }
        cout << t[n - 1] << "\n";
    }
}