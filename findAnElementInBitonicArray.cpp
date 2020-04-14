#include <bits/stdc++.h>
using namespace std;

int findBitonic(int a[], int n, int l, int r)
{
    int mid = l + (r - l) / 2;

    if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
        return mid;

    else if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1])
        findBitonic(a, n, mid + 1, r);

    else if (a[mid] < a[mid - 1] && a[mid] > a[mid + 1])
        findBitonic(a, n, l, mid - 1);
}

int ascBinarySearch(int a[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int dscBinarySearch(int a[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            l = mid + 1;
        else
            l = mid + 1;
    }
    return -1;
}

int search(int a[], int n, int x, int index)
{
    if (x > a[index])
        return -1;
    else if (x == a[index])
        return index;
    else
    {
        int temp = ascBinarySearch(a, 0, index - 1, x);
        if (temp != -1)
            return temp;
        temp = dscBinarySearch(a, index + 1, n - 1, x);
        return temp;
    }
}

int main()
{
    int n, x;
    cin >> n;
    int a[n + 4];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    int index = findBitonic(a, n, 0, n - 1);
    int ans = search(a, n, x, index);

    if (ans == -1)
        cout << "element not found";
    else
        cout << "element found at index " << ans;
}