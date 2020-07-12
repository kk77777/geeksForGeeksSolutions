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
        vector<pair<int, int>> v(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i].first = x;
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i].second = x;
        }
        sort(v.begin(), v.end());

        int y = v[0].second;
        int c = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= y)
            {
                c++;
                y = v[i].second;
            }
            else if (v[i].second < y)
            {
                y = v[i].second;
            }
        }
        cout << c + 1 << "\n";
    }
}