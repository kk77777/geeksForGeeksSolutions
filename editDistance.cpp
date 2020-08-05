#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t[105][105];

int calc(int n, int m, string p, string q)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (t[n - 1][m - 1] != -1)
        return t[n - 1][m - 1];
    if (p[n - 1] == q[m - 1])
        t[n - 1][m - 1] = calc(n - 1, m - 1, p, q);
    else
    {
        t[n - 1][m - 1] = 1 + min(calc(n - 1, m, p, q), min(calc(n, m - 1, p, q), calc(n - 1, m - 1, p, q)));
    }
    return t[n - 1][m - 1];
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        string p, q;
        cin >> p >> q;
        memset(t, -1, sizeof t);
        cout << calc(n, m, p, q) << "\n";
    }
}