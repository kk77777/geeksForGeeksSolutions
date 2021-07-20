// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool solve(int *arr,int n,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return 1;
        }
        if(n==0) return 0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(sum<arr[n]) return dp[n][sum]=solve(arr,n-1,sum,dp);
        return dp[n][sum]=(solve(arr,n-1,sum-arr[n],dp)||solve(arr,n-1,sum,dp));
    }
    
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return 0;
        sum/=2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        return solve(arr,N,sum,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
