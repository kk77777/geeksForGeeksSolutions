#include <bits/stdc++.h>
using namespace std;

void print(set<string> st)
{

    for (auto itr : st)
    {
        if (itr == "")
        {
            cout << "()";
        }
        else
        {
            cout << "(";
            for (int i = 0; i < itr.size() - 1; i++)
            {
                cout << itr[i] << " ";
            }
            cout << itr[itr.size() - 1] << ")";
        }
    }
}

void solve(string ip, string op, set<string> &st)
{
    if (ip.length() == 0)
    {
        st.insert(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1, st);
    solve(ip, op2, st);
    return;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            s.push_back(x);
        }
        sort(s.begin(), s.end());
        string ip = s;
        string op = "";
        set<string> st;
        solve(ip, op, st);
        print(st);
        cout << "\n";
    }
}