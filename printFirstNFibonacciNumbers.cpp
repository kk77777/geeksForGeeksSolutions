#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int n, ll t[90])
{
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << " " << 1;
        return 0;
    }
    t[0] = 1;
    t[1] = 1;
    cout << t[0] << " " << t[1] << " ";
    for (auto i = 2; i < n; i++)
    {
        t[i] = t[i - 1] + t[i - 2];
        cout << t[i] << " ";
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        ll t[90];
        solve(n, t);
        cout << "\n";
    }
}