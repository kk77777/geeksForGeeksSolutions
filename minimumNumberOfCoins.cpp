#include <bits/stdc++.h>
using namespace std;

vector<int> d{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

void solve(long int x)
{
    for (int i = 9; i >= 0 && x != 0; i--)
    {
        if (x / d[i] >= 1)
        {
            x -= d[i];
            cout << d[i] << " ";
            i++;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long int n;
        cin >> n;
        solve(n);
        cout << "\n";
    }
}