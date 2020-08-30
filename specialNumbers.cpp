#include <iostream>
#include <vector>

using namespace std;

void res(int n)
{
    if (n == 0)
    {
        cout << 0 << "\n";
        return;
    }
    vector<int> v;
    while (n > 0)
    {
        int rem = n % 6;
        v.push_back(rem);
        n /= 6;
    }
    int x = v.size() - 1;
    for (int i = x; i >= 0; i--)
    {
        cout << v[i];
    }
    cout << "\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        res(n - 1);
    }
}