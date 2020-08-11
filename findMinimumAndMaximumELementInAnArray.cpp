#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<ll> v;

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }

        ll mn = *min_element(v.begin(), v.end());
        ll mx = *max_element(v.begin(), v.end());
        cout << mn << " " << mx << "\n";
    }
}