#include <bits/stdc++.h>
using namespace std;

void insertItem(stack<int> &s, int ele)
{
    if (s.size() == 0)
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insertItem(s, ele);
    s.push(temp);
    return;
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int ele = s.top();
    s.pop();
    reverseStack(s);
    insertItem(s, ele);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(15);
    s.push(1);
    s.push(7);
    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
}