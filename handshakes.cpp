#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(int n)
{
    ll cat[n + 1];
    cat[0] = 1;
    cat[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        cat[i] = 0;
        for (int j = 0; j < i; j++)
        {
            cat[i] += cat[j] * cat[i - j - 1];
        }
    }
    return cat[n];
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << solve(n / 2) << "\n";
    }
}