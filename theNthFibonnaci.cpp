#include <iostream>
#include <vector>

using namespace std;

vector<int> t(61, 0);

int fib(int n)
{
    t[0] = 0;
    t[1] = 1;
    for (int i = 2; i < 60; i++)
    {
        t[i] = (t[i - 1] + t[i - 2]) % 10;
    }
}

int main()
{
    fib(1000);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << t[n % 60] << "\n";
    }
}