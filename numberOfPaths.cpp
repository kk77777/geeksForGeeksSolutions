#include <bits/stdc++.h>
using namespace std;

int noOfPaths(int n, int m)
{
    if (m == 1 || n == 1)
        return 1;
    return noOfPaths(n - 1, m) + noOfPaths(n, m - 1);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        cout << noOfPaths(n, m) << "\n";
    }
}