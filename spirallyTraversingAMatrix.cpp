#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> v(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }

        int k = 0, l = 0;

        while (k < m && l < n)
        {
            for (int j = l; j < n; j++)
            {
                cout << v[k][j] << " ";
            }
            k++;

            for (int i = k; i < m; i++)
            {
                cout << v[i][n - 1] << " ";
            }
            n--;

            if (k < m)
            {
                for (int j = n - 1; j >= l; j--)
                {
                    cout << v[m - 1][j] << " ";
                }
                m--;
            }

            if (l < n)
            {
                for (int i = m - 1; i >= k; i--)
                {
                    cout << v[i][l] << " ";
                }
                l++;
            }
        }

        cout << "\n";
    }
}