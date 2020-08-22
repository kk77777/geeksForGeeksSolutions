#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;

        int n = s.length();
        if (n == 1)
        {
            if (s[0] - '0' < 6)
            {
                cout << "0\n";
            }
            else
            {
                cout << "10\n";
            }
        }

        else if (s[n - 1] - '0' < 6)
        {
            s[n - 1] = '0';
            cout << s << "\n";
        }

        else
        {
            int x = n - 2;
            s[n - 1] = '0';
            while (s[x] == '9' && x >= 0)
            {
                s[x] = '0';
                x--;
            }
            if (x < 0)
            {
                s.insert(0, "1");
            }
            else
            {
                s[x] = s[x] + 1;
            }
            cout << s << "\n";
        }
    }
}
