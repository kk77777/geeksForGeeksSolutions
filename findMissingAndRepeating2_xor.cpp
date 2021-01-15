// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int res = n;
        for (int i = 0; i < n; i++)
        {
            res = res ^ arr[i] ^ i;
        }
        int fsb = log2(res & -res);
        int x = 0, y = 0;
        // cout << fsb << "\n";
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & (1 << fsb))
            {
                x = x ^ arr[i];
            }
            else
            {
                y = y ^ arr[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & (1 << fsb))
            {
                x = x ^ i;
            }
            else
            {
                y = y ^ i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == y)
            {
                swap(x, y);
            }
        }
        int *fans = new int(2);
        fans[0] = x;
        fans[1] = y;
        return fans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends