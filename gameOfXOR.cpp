#include <iostream>
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
        int ans = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        if (n % 2 == 0)
        {
            ans = 0;
        }
        else
        {
            for (int i = 0; i < n; i += 2)
            {
                ans = ans ^ v[i];
            }
        }
        cout << ans << "\n";
    }
}