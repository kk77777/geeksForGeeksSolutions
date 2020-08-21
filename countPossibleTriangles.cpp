#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int cnt = 0;
        sort(a, a + n);
        for (int i = n - 1; i >= 1; i--)
        {
            int l = 0, r = i - 1;
            while (l < r)
            {
                if (a[l] + a[r] > a[i])
                {
                    cnt += r - l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        cout << cnt << "\n";
    }
}