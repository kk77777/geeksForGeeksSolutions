// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }

        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] << " ";
            }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
bool isSafe(int m[MAX][MAX], int x, int y, int n, vector<vector<int>> &maze)
{
    if (x >= 0 && y >= 0 && x < n && y < n && m[x][y] == 1 && maze[x][y] != 1)
        return true;
    return false;
}

void solve(int m[MAX][MAX], int n, int x, int y, vector<vector<int>> &maze, vector<string> &res, string s)
{
    if (x == n - 1 && y == n - 1)
    {
        res.push_back(s);
        return;
    }
    if (isSafe(m, x, y, n, maze))
    {
        maze[x][y] = 1;
        solve(m, n, x + 1, y, maze, res, s + 'D');
        solve(m, n, x, y - 1, maze, res, s + 'L');
        solve(m, n, x, y + 1, maze, res, s + 'R');
        solve(m, n, x - 1, y, maze, res, s + 'U');
        maze[x][y] = 0;
    }
}

vector<string> findPath(int m[MAX][MAX], int n)
{
    // Your code goes here
    vector<string> res;
    vector<vector<int>> maze(n, vector<int>(n, 0));
    string s;
    if (m[n - 1][n - 1] != 1)
        return res;
    solve(m, n, 0, 0, maze, res, s);
    return res;
}
