#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<ll> v;
        ll p = 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            p *= x;
            v.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cout << p / v[i] << " ";
        }
        cout << "\n";
    }
}