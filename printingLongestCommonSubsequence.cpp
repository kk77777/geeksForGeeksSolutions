#include <bits/stdc++.h>
using namespace std;

int t[105][105];

void printLcs(string x, string y, int m, int n)
{
    int i = m;
    int j = n;
    string s;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

void lcs(string x, string y, int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    printLcs(x, y, m, n);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(t, -1, sizeof t);
        string x, y;
        cin >> x;
        cin >> y;
        int m = x.length();
        int n = y.length();
        lcs(x, y, m, n);
    }
}