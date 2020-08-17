#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int x = n & 170;
        int y = n & 85;
        int ans = (x >> 1 | y << 1);
        cout << ans << "\n";
    }
}