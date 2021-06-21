// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{

    bool isValid(int v[], int mid, int stu, int n)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + v[i] > mid)
            {
                cnt++;
                sum = v[i];
                if (sum > mid)
                    return false;
            }
            else
            {
                sum += v[i];
            }
        }
        if (cnt < stu)
            return true;
        return false;
    }

public:
    //Function to find minimum number of pages.
    int findPages(int v[], int n, int stu)
    {
        //code here
        int l = v[0], h = 0;
        for (int i = 0; i < n; i++)
        {
            l = min(l, v[i]);
            h += v[i];
        }
        int ans = 0;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (isValid(v, mid, stu, n))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends