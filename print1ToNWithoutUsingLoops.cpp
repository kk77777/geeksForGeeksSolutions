#include <bits/stdc++.h>
using namespace std;

int N;
int print(int n)
{
    if (n == N)
    {
        cout << n;
        return 1;
    }
    cout << n << " ";
    print(n + 1);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        N = n;
        print(1);
        cout << "\n";
    }
}