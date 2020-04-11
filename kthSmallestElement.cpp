#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int k;
        cin >> k;
        // priority_queue<int>mh;
        // for(int i=0;i<n;i++){
        //     mh.push(a[i]);
        //     if(mh.size()>k){
        //         mh.pop();
        //     }
        // }
        sort(a.begin(), a.end());
        cout << a[k - 1] << "\n";
    }
}