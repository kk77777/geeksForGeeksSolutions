#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {

        string str;
        cin >> str;

        bool flag = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                flag = 1;
                break;
            }
        }

        stack<char> s;

        int i = str.length() - 1;
        while (i >= 0 && flag != 0)
        {
            if (str[i] != '.')
            {
                s.push(str[i]);
                i--;
            }
            else
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ".";
                i--;
            }
        }
        i = 0;
        while (str[i] != '.' && flag != 0)
        {
            cout << str[i];
            i++;
        }
        if (flag == 0)
        {
            cout << str;
        }
        cout << "\n";
    }
}