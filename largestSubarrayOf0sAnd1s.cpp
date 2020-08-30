// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    // Your code here
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = -1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }

        if (mp.find(sum + N) != mp.end())
        {
            if (maxLen < i - mp[sum + N])
            {
                maxLen = i - mp[sum + N];
            }
        }
        else
        {
            mp[sum + N] = i;
        }
    }
    return maxLen;
}
