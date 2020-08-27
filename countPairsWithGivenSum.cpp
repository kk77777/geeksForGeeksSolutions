#include <iostream>
#include <unordered_map>
#include <vector>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k, cnt = 0;
        cin >> n >> k;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (mp[x] != 0)
            {

                cnt += mp[x];
                mp[k - x]++;
            }
            else
            {
                mp[k - x]++;
            }
        }
        cout << cnt << "\n";
    }
}