#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        // priority_queue<int,vector<int>,greater<int>>mh;
        // for(int i=0;i<n;i++){
        //     mh.push(v[i]);
        //     if(mh.size()>k){
        //         mh.pop();
        //     }
        // }
        // // reverse()
        // vector<int>a(mh.size(),0);
        // while(mh.size()>0){
        //     a[mh.size()-1]=mh.top();
        //     mh.pop();
        // }
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0; i < k; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}