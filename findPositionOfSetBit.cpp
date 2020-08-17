#include <iostream>
#include <vector>
#define ll long int

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        int cnt = 0, ans;
        while (n > 0)
        {
            v.push_back(n % 2);
            n /= 2;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                cnt++;
                ans = i + 1;
            }
        }
        (cnt > 1) ? cout << -1 : cout << ans;
        cout << "\n";
    }
}