int countZeros(int a[MAX][MAX], int n)
{
    //Your code here
    int r = n - 1, c = 0, cnt = 0;
    while (c < n)
    {
        while (a[r][c])
        {
            if (--r < 0)
            {
                return cnt;
            }
        }
        cnt += (r + 1);
        c++;
    }
    return cnt;
}
