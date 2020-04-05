#include <bits/stdc++.h>
using namespace std;

int ans = -1;
int first(int a[], int f, int l, int x)
{

    if (f <= l)
    {
        int mid = f + (l - f) / 2;
        if (a[mid] == x)
        {
            ans = mid;
            return first(a, f, mid - 1, x);
        }
        else if (a[mid] > x)
        {
            return first(a, f, mid - 1, x);
        }
        else
        {
            return first(a, mid + 1, l, x);
        }
    }
    return ans;
}

int last(int a[], int f, int l, int x)
{
    if (f <= l)
    {
        int mid = f + (l - f) / 2;
        if (a[mid] == x)
        {
            ans = mid;
            return last(a, mid + 1, l, x);
        }
        else if (a[mid] > x)
        {
            return last(a, f, mid - 1, x);
        }
        else
        {
            return last(a, mid + 1, l, x);
        }
    }
    return ans;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ans = -1;
        int n, x;
        cin >> n >> x;
        int a[n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int res = first(a, 0, n - 1, x);
        if (res == -1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << last(a, 0, n - 1, x) - res + 1 << "\n";
        }
    }
}