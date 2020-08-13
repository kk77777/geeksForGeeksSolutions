#include <iostream>
#define m 1000000007
#define ll long long int

using namespace std;

ll power(ll n, ll r)
{
    if (r == 0)
        return 1;
    ll temp = power(n, r / 2);
    if (r % 2 == 0)
    {
        return ((temp % m) * (temp % m)) % m;
    }
    else
    {
        return (n * ((temp * temp) % m)) % m;
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        ll N = n;
        ll rev = 0;
        while (n > 0)
        {
            ll r = n % 10;
            rev = rev * 10 + r;
            n /= 10;
        }
        cout << power(N, rev) << "\n";
    }
}