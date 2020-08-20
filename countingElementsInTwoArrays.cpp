// { Driver Code Starts
// C++ implementation of For each element in 1st
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>

using namespace std;

// function returns the index of largest element
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1.
int binary_search(int arr[], int l, int h, int x);

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],
                                    int m, int n);

// Driver program to test above
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++)
            cin >> arr1[i];
        for (int j = 0; j < n; j++)
            cin >> arr2[j];
        vector<int> res = countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array

int search(int a[], int k, int n)
{
    int ans = -1;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] < k)
        {
            s = mid + 1;
        }
        else if (a[mid] > k)
        {
            e = mid - 1;
        }
    }
    if (ans == -1)
        ans = e;
    return ans + 1;
}

vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],
                                    int m, int n)
{
    //Your code goes here
    sort(arr2, arr2 + n);
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int cnt = search(arr2, arr1[i], n);
        res.push_back(cnt);
    }
    return res;
}