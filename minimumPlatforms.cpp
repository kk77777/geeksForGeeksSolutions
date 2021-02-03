// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);
    int a, d, ans = 1, plat = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            plat--;
            j++;
        }
        if (plat > ans)
            ans = plat;
    }
    return ans;
}

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        cout << findPlatform(arr, dep, n) << endl;
    }
    return 0;
} // } Driver Code Ends