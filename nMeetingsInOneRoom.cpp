// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends

struct meeting
{
    int s;
    int e;
    int pos;
};

bool comparator(struct meeting m1, struct meeting m2)
{
    if (m1.e < m2.e)
        return true;
    else if (m1.e > m2.e)
        return false;
    else if (m1.pos < m2.pos)
        return true;
}

int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    int cnt = 1;
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].s = start[i];
        meet[i].e = end[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comparator);
    // vector<int> ans;
    int l = meet[0].e;
    // ans.push_back(meet[0].pos);
    for (int i = 1; i < n; i++)
    {
        if (meet[i].s > l)
        {
            // ans.push_back(meet[i].pos);
            l = meet[i].e;
            cnt++;
        }
    }
    return cnt;
}