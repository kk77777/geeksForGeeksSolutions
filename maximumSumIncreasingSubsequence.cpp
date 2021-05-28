// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    int msis(int arr[], vector<int> &dp, int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if (arr[i] > arr[j] && (dp[j] + arr[i] > dp[i]))
                {
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
        int mx = INT_MIN;
        for (auto it : dp)
        {
            mx = max(it, mx);
        }
        return mx;
    }

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        if (n == 1)
            return arr[0];
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = arr[i];
        }
        return msis(arr, dp, n);
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
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends