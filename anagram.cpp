#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool solve(string a, string b)
{
    if (a.length() != b.length())
        return false;
    unordered_map<char, int> s;
    for (int i = 0; i < a.length(); i++)
    {
        s[a[i]]++;
        s[b[i]]--;
    }
    for (auto i : s)
    {
        if (i.second)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string a, b;
        cin >> a >> b;
        solve(a, b) ? cout << "YES\n" : cout << "NO\n";
    }
}