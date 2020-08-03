#include <iostream>
#include <set>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        set<char> nuts, bolts;
        for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            nuts.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            if (nuts.find(x) != nuts.end())
            {
                bolts.insert(x);
            }
        }
        for (auto i = bolts.begin(); i != bolts.end(); i++)
        {
            cout << *i << " ";
        }
        cout << "\n";
        for (auto i = bolts.begin(); i != bolts.end(); i++)
        {
            cout << *i << " ";
        }
        cout << "\n";
    }
}