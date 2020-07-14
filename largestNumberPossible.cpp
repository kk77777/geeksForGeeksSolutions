#include <bits/stdc++.h>
using namespace std;

int solve(int n, int s)
{
    if ((s == 0 && n > 0) || (s > n * 9))
    {
        cout << -1;
    }
    else
    {
        while (n >= 1)
        {
            if (s >= 9)
            {
                cout << 9;
                s = s - 9;
            }
            else if (s == 0)
            {
                cout << 0;
            }
            else
            {
                cout << s;
                s = 0;
            }
            n--;
        }
    }
    return 0;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, s;
        cin >> n >> s;
        solve(n, s);
        cout << "\n";
    }
}