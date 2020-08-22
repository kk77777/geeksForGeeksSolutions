#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s]++;
        }
        int mx = 0;
        for (auto i : mp)
        {
            if (i.second > mx)
            {
                mx = i.second;
            }
        }
        for (auto i : mp)
        {
            if (i.second == mx)
            {
                cout << i.first << " " << i.second << "\n";
                break;
            }
        }
    }
}
