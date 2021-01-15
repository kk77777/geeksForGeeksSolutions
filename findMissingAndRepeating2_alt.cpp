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
        int *res = new int(2);
        int x, y;
        long int sum = n * (n + 1) / 2;
        long int sqSum = (n * (n + 1) * (2 * n + 1)) / 6;
        for (int i = 0; i < n; i++)
        {
            sum -= arr[i];
            sqSum -= (arr[i] * arr[i]);
        }
        x = (sqSum / sum) + sum;
        x /= 2;
        y = x - sum;
        res[0] = y;
        res[1] = x;
        return res;
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