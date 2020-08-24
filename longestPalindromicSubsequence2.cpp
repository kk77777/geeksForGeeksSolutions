#include <iostream>
#include <string>
#include <algorithm>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int lps(string s)
{
    int n = s.length();
    int t[n][n] = {0};
    for (int i = 0; i < n; i++)
        t[i][i] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            t[i][i + 1] = 2;
        else
            t[i][i + 1] = 1;
    }
    int j;
    for (int l = 3; l <= n; l++)
    {
        for (int i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;
            if (s[i] == s[j])
                t[i][j] = t[i + 1][j - 1] + 2;
            else
            {
                t[i][j] = max(t[i][j - 1], t[i + 1][j]);
            }
        }
    }
    return t[0][n - 1];
    return 0;
}

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        cout << lps(s) << "\n";
    }
}