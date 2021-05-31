// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    int solve(int n, int x, int y, int z, vector<int> &dp)
    {
        dp[0] = 0;
        int xNo = INT_MIN, yNo = INT_MIN, zNo = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (i - x >= 0)
            {
                xNo = 1 + dp[i - x];
            }
            if (i - y >= 0)
            {
                yNo = 1 + dp[i - y];
            }
            if (i - z >= 0)
            {
                zNo = 1 + dp[i - z];
            }
            dp[i] = max(xNo, max(yNo, zNo));
        }
        return dp[n];
    }

public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n + 1, -1);
        int ans = solve(n, x, y, z, dp);
        if (ans < 0)
            return 0;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends