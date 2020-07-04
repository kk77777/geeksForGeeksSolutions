void insert(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sorted(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sorted(s);
    insert(s, temp);
}

void SortedStack ::sort()
{
    sorted(s);
}