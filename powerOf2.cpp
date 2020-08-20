#include <iostream>
#include <cmath>
#define ll long long int

using namespace std;

bool check(ll n)
{
    if (n == 0)
        return false;
    ll m = n - 1;
    ll res = (n & m);
    if (res)
        return false;
    else
        return true;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        check(n) ? cout << "YES\n" : cout << "NO\n";
    }
}