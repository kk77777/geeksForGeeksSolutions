// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
    bool isSafe(vector<vector<int>> &a, int x, int y, int n)
    {
        for (int row = 0; row < x; row++)
        {
            if (a[row][y] == 1)
                return false;
        }
        int row = x, col = y;
        while (row >= 0 && col >= 0)
        {
            if (a[row][col] == 1)
                return false;
            row--;
            col--;
        }
        row = x;
        col = y;
        while (row >= 0 && col < n)
        {
            if (a[row][col] == 1)
                return false;
            row--;
            col++;
        }
        return true;
    }

    void isnQueen(vector<vector<int>> &a, int x, int n, vector<vector<int>> &ans)
    {
        if (x >= n)
        {
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i][j] == 1)
                    {
                        res.push_back(j + 1);
                    }
                }
            }
            ans.push_back(res);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(a, x, col, n))
            {
                a[x][col] = 1;
                isnQueen(a, x + 1, n, ans);
                a[x][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> a(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        isnQueen(a, 0, n, ans);
        return ans;
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends