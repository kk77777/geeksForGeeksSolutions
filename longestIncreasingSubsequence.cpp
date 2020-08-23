#include <iostream>
#include <vector>
#include <algorithm>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int lis(vector<int> &v)
{
    int n = v.size();
    if (n == 1)
        return 1;
    vector<int> t(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                t[i] = max(t[i], t[j] + 1);
            }
        }
    }
    int ans = t[0];
    for (int i = 1; i < n; i++)
    {
        if (t[i] > ans)
        {
            ans = t[i];
        }
    }
    return ans;
}

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << lis(v) << "\n";
    }
}