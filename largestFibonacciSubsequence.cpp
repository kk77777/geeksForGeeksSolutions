#include <iostream>
#include <unordered_map>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int fib(unordered_map<int, int> &mp)
{
    mp[0] = 0, mp[1] = 1, mp[2] = 2;
    for (int i = 3; i < 20; i++)
    {
        mp[i] = mp[i - 1] + mp[i - 2];
    }
}

int main()
{
    fast
        unordered_map<int, int>
            mp;
    fib(mp);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if (it->second == x)
                {
                    cout << x << " ";
                    continue;
                }
            }
        }
        cout << "\n";
    }
}