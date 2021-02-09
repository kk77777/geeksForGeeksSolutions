#include <bits/stdc++.h>
using namespace std;

double nthRoot(double x, int n)
{
    double l, h;
    if (x >= 0 && x <= 1)
    {
        l = x;
        h = 1;
    }
    else
    {
        l = 1;
        h = x;
    }
    double err = 0.0001;
    double g = (l + h) / 2;
    while (abs(pow(g, n) - x) >= err)
    {
        if (pow(g, n) > x)
        {
            h = g;
        }
        else
        {
            l = g;
        }
        g = (l + h) / 2;
    }
    return g;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        double x;
        cin >> x;
        int n;
        cin >> n;
        cout << fixed << setprecision(4) << nthRoot(x, n) << "\n";
    }
}