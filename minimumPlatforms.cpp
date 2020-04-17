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
        vector<int> a, d;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            d.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());

        int p = 1;
        int result = 1;
        int j = 0, i = 1;
        while (i < n && j < n)
        {
            if (a[i] <= d[j])
            {
                p++;
                i++;
                if (p > result)
                {
                    result = p;
                }
            }
            else
            {
                p--;
                j++;
            }
        }
        cout << result << "\n";
    }
}