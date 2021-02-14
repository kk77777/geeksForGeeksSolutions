// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits
int findLargestPowerOf2(int x)
{
    int i = 0;
    while ((1 << i) <= x)
    {
        i++;
    }
    return i - 1;
}

int countSetBits(int n)
{
    // Your logic here
    if (n == 0)
        return 0;
    int x = findLargestPowerOf2(n);
    int ans1 = x * (1 << (x - 1));
    int ans2 = n - (1 << x) + 1;
    int rem = n - (1 << x);
    int fans = ans1 + ans2 + countSetBits(rem);
    return fans;
}

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) //while testcases exist
    {
        int n;
        cin >> n; //input n

        cout << countSetBits(n) << endl; // print the answer
    }
    return 0;
}
// } Driver Code Ends