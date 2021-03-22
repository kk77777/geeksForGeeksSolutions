#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define q 13
#define d 10

void rabinKarp(string s, string pattern)
{
    int n = s.length();
    int m = pattern.length();
    int i, j, p = 0, t = 0, h = 1;
    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + s[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (s[i + j] != pattern[j])
                    break;
            }
            if (j == m)
            {
                cout << i << "\n";
            }
        }
        if (i < n - m)
        {
            t = (d * (t - s[i] * h) + s[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        string s, p;
        getline(cin, s);
        getline(cin, p);
        rabinKarp(s, p);
    }
    return 0;
}
