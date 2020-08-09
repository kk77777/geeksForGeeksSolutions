#include <iostream>
#include <queue>
#include <vector>
#define ll long int
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        ll k, n;
        cin >> k >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (pq.size() < k)
            {
                pq.push(x);
                if (pq.size() == k)
                {
                    cout << pq.top() << " ";
                }
                else
                {
                    cout << -1 << " ";
                }
            }
            else if (pq.size() == k && pq.top() < x)
            {
                pq.pop();
                pq.push(x);
                cout << pq.top() << " ";
            }
            else if (pq.size() == k && pq.top() >= x)
            {
                cout << pq.top() << " ";
            }
        }
        cout << "\n";
    }
}