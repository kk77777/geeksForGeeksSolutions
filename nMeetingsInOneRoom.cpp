#include <bits/stdc++.h>
using namespace std;

struct activity
{
    int s, e, index;
};

bool compareActivity(activity a, activity b)
{
    return a.e < b.e;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<activity> v(n, {0, 0, 0});
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i].s = x;
            v[i].index = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[i].e = x;
        }
        sort(v.begin(), v.end(), compareActivity);

        int y = v[0].e;
        int c = 0;
        cout << v[0].index << " ";
        for (int i = 1; i < n; i++)
        {
            if (v[i].s >= y)
            {
                c++;
                cout << v[i].index << " ";
                y = v[i].e;
            }
            else if (v[i].e < y)
            {
                y = v[i].e;
            }
        }
        cout << "\n";
    }
}