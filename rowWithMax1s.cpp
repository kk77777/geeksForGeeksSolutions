#include <iostream>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mx 1000

using namespace std;

int max1(int a[][1000], int n, int m)
{
    int res;
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (a[i][j] == 1)
        {
            res = i;
            j--;
        }
        else
        {
            i++;
        }
    }
    return res;
}

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        int a[mx][mx];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << max1(a, n, m) << "\n";
    }
}