#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void getZarr(string str, int *z)
{
    int n = str.length();
    int l, r, ri;
    l = r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && str[r - l] == str[r])
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            ri = i - l;
            if (z[ri] + i - 1 < r)
            {
                z[i] = z[ri];
            }
            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}

void searchPattern(string text, string pattern)
{
    string con = pattern + "$" + text;
    int n = con.length();
    int z[n];
    getZarr(con, z);
    for (int i = 0; i < n; i++)
    {
        if (z[i] == pattern.length())
        {
            cout << i - pattern.length() - 1 << "\n";
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
        string text, pattern;
        getline(cin, text);
        getline(cin, pattern);
        searchPattern(text, pattern);
    }
    return 0;
}