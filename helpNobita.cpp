#include <iostream>
#include <map>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        map<int, int> t;
        string s;
        cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < s.length(); i++)
        {
            t[s[i] - 96]++;
        }

        for (auto i = 0; i <= 26; i++)
        {
            if (i % 2 == 0 && t[i] % 2 == 0 && t[i] != 0)
            {
                x++;
            }
            else if (i % 2 != 0 && t[i] % 2 != 0 && t[i] != 0)
            {
                y++;
            }
        }

        if ((x + y) % 2 == 0)
        {
            cout << "EVEN\n";
        }
        else
        {
            cout << "ODD\n";
        }
    }
}