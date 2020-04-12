#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        priority_queue<int, vector<int>, greater<int>> mh;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            mh.push(a[i]);
            if (mh.size() > k)
            {
                v.push_back(mh.top());
                mh.pop();
            }
        }
        while (mh.size() > 0)
        {
            v.push_back(mh.top());
            mh.pop();
        }
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}