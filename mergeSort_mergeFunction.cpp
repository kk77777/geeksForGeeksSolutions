void merge(int a[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = 0;
    int n = (sizeof(a) / sizeof(a[0]));
    int temp[r - l] = {0};
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= m)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }
    for (i = l; i <= r; i++)
    {
        a[i] = temp[i - l];
    }
}