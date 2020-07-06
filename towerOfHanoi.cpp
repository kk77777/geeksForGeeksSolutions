#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int h, int n, int &cnt)
{
    cnt++;
    if (n == 1)
    {
        cout << "move disk " << n << " from rod " << s << " to rod " << d << "\n";
        return;
    }
    solve(s, h, d, n - 1, cnt);
    cout << "move disk " << n << " from rod " << s << " to rod " << d << "\n";
    solve(h, d, s, n - 1, cnt);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, cnt = 0, s = 1, h = 2, d = 3;
        cin >> n;
        solve(s, d, h, n, cnt);
        cout << cnt << "\n";
    }
}