#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int sm = 0, flag = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            sm += x;
            if (s.find(sm) != s.end())
            {
                flag = 1;
            }
            if (sm == 0)
                flag = 1;
            s.insert(sm);
        }
        flag ? cout << "Yes\n" : cout << "No\n";
    }
}