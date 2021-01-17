// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

#define ll long long

ll merge(ll arr[], ll l, ll r, ll mid, ll temp[])
{
    ll i, j, k;
    ll inv_cnt = 0;
    i = l, j = mid, k = l;
    while ((i <= mid - 1) && (j <= r))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_cnt += (mid - i);
        }
    }
    while (i < mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }
    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
    return inv_cnt;
}

ll mergeSort(ll arr[], ll l, ll r, ll temp[])
{
    ll mid, inv_cnt = 0;
    if (l < r)
    {
        mid = (l + r) / 2;
        inv_cnt += mergeSort(arr, l, mid, temp);
        inv_cnt += mergeSort(arr, mid + 1, r, temp);
        inv_cnt += merge(arr, l, r, mid + 1, temp);
    }
    return inv_cnt;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    ll temp[N];
    ll ans = mergeSort(arr, 0, N - 1, temp);
    return ans;
}

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends