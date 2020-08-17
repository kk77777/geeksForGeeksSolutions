#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> s;
        vector<int> v;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string c;
            cin >> c;
            sort(c.begin(), c.end());
            s.push_back(c);
            mp[s[i]]++;
        }
        for (auto i : mp)
        {
            v.push_back(i.second);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}