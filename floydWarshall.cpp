// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &v)
    {
        // Code here
        int n = v.size();
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;
                    if (v[i][k] == -1 || v[k][j] == -1)
                        continue;
                    int x = v[i][j] == -1 ? INT_MAX : v[i][j];
                    if (x > (v[i][k] + v[k][j]))
                    {
                        v[i][j] = (v[i][k] + v[k][j]);
                    }
                }
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends