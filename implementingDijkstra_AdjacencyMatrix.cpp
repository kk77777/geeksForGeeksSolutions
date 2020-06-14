vector <int> dijkstra(vector<vector<int>> g, int src, int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n,INT_MAX);
    bool vis[n]={0};
    pq.push({0,src});
    dist[src]=0;
    
    while(!pq.empty()){
        pair<int,int>p=pq.top();
        pq.pop();
        int u=p.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<n;i++){
            if(g[u][i]!=0){
                int v=i;
                int wt=g[u][i];
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    vector<int>v;
    for(int i=0;i<n;i++){
        v.push_back(dist[i]);
    }
    return v;
}