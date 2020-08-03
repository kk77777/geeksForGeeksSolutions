#include <iostream>
#include <vector>
#include <unordered_set>
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
        int cnt = 0;
        vector<vector<int>> v(n, vector<int>(n, 0));
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = 0; j < n; j++)
            {
                s.insert(v[i][j]);
            }
            for (auto i = s.begin(); i != s.end(); i++)
            {
                m[*i]++;
            }
        }
        for (auto i = m.begin(); i != m.end(); i++)
        {
            if (i->second == n)
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}