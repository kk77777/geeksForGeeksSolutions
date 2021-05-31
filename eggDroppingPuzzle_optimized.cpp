// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    int solve(int n, int f, vector<vector<int>> &dp)
    {
        if (f == 0 || f == 1)
            return f;
        if (n <= 1)
            return f;
        if (dp[n][f] != -1)
            return dp[n][f];
        int mn = INT_MAX;
        for (int k = 1; k <= f; k++)
        {
            int low, high;
            if (dp[n - 1][k - 1] != -1)
            {
                low = dp[n - 1][k - 1];
            }
            else
            {
                low = solve(n - 1, k - 1, dp);
            }
            if (dp[n][f - k] != -1)
            {
                high = dp[n][f - k];
            }
            else
            {
                high = solve(n, f - k, dp);
            }
            int temp = 1 + max(low, high);
            mn = min(temp, mn);
        }
        return dp[n][f] = mn;
    }

public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        //calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends