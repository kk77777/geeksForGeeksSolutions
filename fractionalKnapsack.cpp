// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(struct Item a, struct Item b)
{
    double ra = (double)a.value / (double)a.weight;
    double rb = (double)b.value / (double)b.weight;
    return ra > rb;
}

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr + n, comp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "value = " << arr[i].value << "   weight = " << arr[i].weight << "\n";
    // }
    double ans = 0;
    int cw = 0;
    for (int i = 0; i < n; i++)
    {
        if (cw + arr[i].weight <= W)
        {
            ans += arr[i].value;
            cw += arr[i].weight;
        }
        else
        {
            int rem = W - cw;
            ans += (arr[i].value * (double(rem) / double(arr[i].weight)));
            break;
        }
    }
    return ans;
}

// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        cout << fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends