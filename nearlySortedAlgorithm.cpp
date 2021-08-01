#include <iostream>
#include<queue>
using namespace std;

class Solution{
    public:
    void nearlySort(int arr[],int n,int k){
        int s=n==k?k:k+1;
        priority_queue<int,vector<int>,greater<int>>pq(arr,arr+s);
        int index=0;
        for(int i=k+1;i<n;i++){
            arr[index++]=pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            arr[index++]=pq.top();
            pq.pop();
        }
    }
};


int main() {
	//code
	int tc;
	cin>>tc;
	while(tc--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution obj;
	    obj.nearlySort(arr,n,k);
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
