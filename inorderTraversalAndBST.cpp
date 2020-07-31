#include <iostream>
#include <vector>
using namespace std;

bool isSort(vector<int> v, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] >= v[i])
            return false;
    }
    return true;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        if (isSort(v, n))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}