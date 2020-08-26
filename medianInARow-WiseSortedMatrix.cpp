#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int median(vector<vector<int>> &v, int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        if (v[i][0] < min)
            min = v[i][0];
        if (v[i][c - 1] > max)
            max = v[i][c - 1];
    }
    int d = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            cnt += upper_bound(&v[i][0], &v[i][c], mid) - &v[i][0];
        }
        if (cnt < d)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> v(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> v[i][j];
            }
        }
        cout << median(v, r, c) << "\n";
    }
}