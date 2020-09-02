// { Driver Code Starts
#include <bits/stdc++.h>

#define N 105
using namespace std;

int *mergeKArrays(int arr[][N], int k);

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int arr[N][N];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        int *output = mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k)
{
    //code here
    int *a = new int[k * k];
    int l[k];

    for (int i = 0; i < k; i++)
    {
        l[i] = 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], i});
    }

    int j = 0;
    for (int i = 0; i < k * k; i++)
    {
        pair<int, int> p = pq.top();
        pq.pop();
        a[j] = p.first;
        j++;

        if (l[p.second] < k - 1)
        {
            l[p.second]++;
            pq.push({arr[p.second][l[p.second]], p.second});
        }
    }

    return a;
}