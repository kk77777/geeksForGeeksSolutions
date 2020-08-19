int findPeakElement(int arr[], int n, int l, int h)
{

    int mid = l + (h - l) / 2;
    if (mid == 0 && arr[mid] >= arr[mid + 1])
        return mid;
    else if (mid == n - 1 && arr[mid] >= arr[mid - 1])
        return mid;
    else if (mid != 0 && mid != n - 1 && arr[mid - 1] <= arr[mid] && arr[mid] >= arr[mid + 1])
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return findPeakElement(arr, n, l, mid - 1);
    else
        return findPeakElement(arr, n, mid + 1, h);
}

int peakElement(int arr[], int n)
{
    // Your code here
    return findPeakElement(arr, n, 0, n - 1);
}