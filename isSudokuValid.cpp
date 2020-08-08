#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool check(vector<vector<int>> v)
{
    for (int i = 0; i < 9; i++)
    {
        unordered_set<int> s;
        for (int j = 0; j < 9; j++)
        {
            if (v[i][j] != 0)
            {
                if (s.find(v[i][j]) == s.end())
                {
                    s.insert(v[i][j]);
                }
                else
                {
                    return false;
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        unordered_set<int> s;
        for (int j = 0; j < 9; j++)
        {
            if (v[j][i] != 0)
            {
                if (s.find(v[j][i]) == s.end())
                {
                    s.insert(v[j][i]);
                }
                else
                {

                    return false;
                }
            }
        }
    }

    for (int x = 0; x < 9; x = x + 3)
    {
        for (int i = 0; i < 9; i = i + 3)
        {
            unordered_set<int> s;
            for (int j = x; j < x + 3; j++)
            {
                for (int k = i; k < i + 3; k++)
                {
                    if (v[j][k] != 0)
                    {
                        if (s.find(v[j][k]) == s.end())
                        {
                            s.insert(v[j][k]);
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<vector<int>> v(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> v[i][j];
            }
        }

        check(v) ? cout << 1 << "\n" : cout << 0 << "\n";
    }
}