#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;

        int a[m + 5];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        int n;
        cin >> n;

        int table[n + 1];
        memset(table, 0, sizeof table);

        table[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = a[i]; j <= n; j++)
            {
                table[j] += table[j - a[i]];
            }
        }
        cout << table[n] << "\n";
    }
}