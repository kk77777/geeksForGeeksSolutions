// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int matSearch(vector<vector<int>> &mat, int n, int m, int x)
    {
        // your code here
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int h = m - 1;
            while (l <= h)
            {
                // cout << "low = " << l << "\n";
                // cout << "high = " << h << "\n";
                int mid = l + (h - l) / 2;
                // cout << "mid = " << mid << "\n";
                // cout << "mid element = " << mat[i][mid] << "\n";
                if (mat[i][mid] == x)
                {
                    return 1;
                }
                else if (mat[i][mid] > x)
                {
                    h = mid - 1;
                }
                else if (mat[i][mid] < x)
                {
                    l = mid + 1;
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];

        int x;
        cin >> x;
        Solution ob;
        cout << ob.matSearch(arr, n, m, x) << endl;
    }
} // } Driver Code Ends