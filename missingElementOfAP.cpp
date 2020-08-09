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
        vector<int> v(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        int asum = ((n + 1) * (v[0] + v[n - 1])) / 2;
        cout << asum - sum << "\n";
    }
}