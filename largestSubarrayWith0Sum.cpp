int maxLen(int a[], int n)
{
    // Your code here
    unordered_map<int, int> prevSum;
    int sum = 0;
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] == 0 && maxLength == 0)
            maxLength = 1;
        if (sum == 0)
        {
            maxLength = i + 1;
        }
        if (prevSum.find(sum) != prevSum.end())
        {
            maxLength = max(maxLength, i - prevSum[sum]);
        }
        else
        {
            prevSum[sum] = i;
        }
    }
    return maxLength;
}
