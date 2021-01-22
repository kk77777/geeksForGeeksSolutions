#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a[100], n, k, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            int xorr = 0;
            for (int j = i; j < n; j++)
            {
                xorr = xorr ^ a[j];
                if (xorr == k)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}