bool logic(struct val a, struct val b)
{
    return a.first < b.first;
}

/*You are required to complete this method*/
int maxChainLen(struct val v[], int n)
{
    //Your code here
    sort(v, v + n, logic);
    vector<int> x(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].first > v[j].second && x[i] < x[j] + 1)
            {
                x[i] = x[j] + 1;
            }
        }
    }
    int mx = x[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(x[i], mx);
    }
    return mx;
}
v