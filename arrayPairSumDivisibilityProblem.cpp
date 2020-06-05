#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> v, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i] % k]++;
    }
    for (int i = 0; i < v.size(); i++)
    {
        int rem = v[i] % k;
        if (2 * rem == k)
        {
            if (m[rem] % 2 != 0)
            {
                return false;
            }
        }
        else if (rem == 0)
        {
            if (m[rem] % 2 != 0)
            {
                return false;
            }
        }
        else
        {
            if (m[rem] != m[k - rem])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int tc;
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
        int k;
        cin >> k;
        f(v, k) ? cout << "True\n" : cout << "False\n";
    }
}