#include <bits/stdc++.h>
using namespace std;

int f(vector<int> a, vector<int> b, int m, int n, int diff)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] + b[j]) == diff)
            return 1;
        else if (a[i] > b[j])
            i++;
        else
            j++;
    }
    return -1;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        int suma = 0, sumb = 0;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            suma += x;
        }
        for (int i = 0; i < m; i++)
        {
            int y;
            cin >> y;
            b.push_back(y);
            sumb += y;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int diff = abs(suma - sumb);
        cout << f(a, b, m, n, diff) << "\n";
    }
}