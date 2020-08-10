#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), greater<int>());
        cout << s << "\n";
    }
}