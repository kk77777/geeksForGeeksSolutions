#include <iostream>
#include <vector>
#define m 1000000007
using namespace std;

vector<int> v(101, 0);

void solve(int n)
{
    v[0] = 0;
    v[1] = 2;
    v[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        v[i] = (v[i - 2] % m + v[i - 1] % m) % m;
    }
}

int main()
{
    solve(100);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << v[n] << "\n";
    }
}