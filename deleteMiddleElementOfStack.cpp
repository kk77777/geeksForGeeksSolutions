#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(temp);
}

stack<int> deleteMiddleElement(stack<int> &s, int k)
{
    if (s.size() == 0)
        return s;
    solve(s, k);
    return s;
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(15);
    s.push(1);
    s.push(7);
    int k = s.size() / 2 + 1;
    stack<int> p = deleteMiddleElement(s, k);
    while (!p.empty())
    {
        cout << p.top() << "\n";
        p.pop();
    }
}