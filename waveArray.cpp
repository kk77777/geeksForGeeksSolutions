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
        for (auto i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (auto i = 0; i < n - 1; i += 2)
        {
            ll temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
        for (auto i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}