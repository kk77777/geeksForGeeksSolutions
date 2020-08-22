#include <iostream>
#include <unordered_map>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int main()
{
    fast int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        bool flag = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]])
            {
                flag = 1;
                break;
            }
            mp[x - a[i]]++;
        }
        flag ? cout << "Yes\n" : cout << "No\n";
    }
}