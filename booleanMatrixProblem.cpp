#include <iostream>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        cin >> m >> n;
        int a[m][n];
        bool rf = 0, cf = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (a[i][0] == 1)
            {
                rf = 1;
                break;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (a[0][j] == 1)
            {
                cf = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    a[i][0] = 1;
                    a[0][j] = 1;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (a[i][0] == 1 || a[0][j] == 1)
                {
                    a[i][j] = 1;
                }
            }
        }
        if (rf)
        {
            for (int i = 0; i < m; i++)
            {
                a[i][0] = 1;
            }
        }
        if (cf)
        {
            for (int j = 0; j < n; j++)
            {
                a[0][j] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}