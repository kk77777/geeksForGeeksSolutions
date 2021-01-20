// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void sort012(int[], int);

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

void sort012(int a[], int n)
{
    // coode here
    int l, h, m;
    l = m = 0;
    h = n - 1;
    while (m <= h)
    {
        switch (a[m])
        {
        case 0:
            swap(a[l++], a[m++]);
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(a[m], a[h--]);
            break;
        }
    }
}