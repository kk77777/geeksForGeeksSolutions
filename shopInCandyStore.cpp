#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int minSum = 0, x = 0;
        for (int i = 0; i < n - x; i++)
        {
            minSum += v[i];
            x += k;
        }
        sort(v.begin(), v.end(), greater<int>());
        int maxSum = 0, y = 0;
        for (int i = 0; i < n - y; i++)
        {
            maxSum += v[i];
            y += k;
        }

        cout << minSum << " " << maxSum << "\n";
    }
}