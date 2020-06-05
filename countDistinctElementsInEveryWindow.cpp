vector<int> countDistinct(int a[], int n, int k)
{

    unordered_map<int, int> v;
    vector<int> x;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (v[a[i]] > 0)
        {
            v[a[i]]++;
        }
        else
        {
            v[a[i]] = 1;
            cnt++;
        }
    }
    x.push_back(cnt);
    for (int i = k; i < n; i++)
    {
        if (v[a[i - k]] == 1)
        {
            cnt--;
            v[a[i - k]] = 0;
        }
        else
        {
            v[a[i - k]]--;
        }
        if (v[a[i]] == 0)
        {
            cnt++;
            v[a[i]] = 1;
        }
        else
        {
            v[a[i]]++;
        }
        x.push_back(cnt);
    }

    return x;
}