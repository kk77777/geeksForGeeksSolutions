// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int solve(int i, int j, int a[], vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int temp = solve(i, k, a, dp) + solve(k + 1, j, a, dp) + (a[i - 1] * a[k] * a[j]);
            if (temp < mn)
            {
                mn = temp;
            }
        }
        return dp[i][j] = mn;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return solve(1, N - 1, arr, dp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends