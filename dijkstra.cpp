#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>&adj,vector<int>&vis,vector<int>&dist,int src){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vis[src]=1;
dist[src]=0;
pq.push({0,src});
while(!pq.empty()){
    int node=pq.top().second;
    int weight=pq.top().first;
    pq.pop();
    vis[node]=1;
    for(auto it: adj[node]){
        int n=it.first;
        int w=it.second;
        if(weight+w<dist[n]){
            dist[n]=weight+w;
            pq.push({dist[n],n});
        }
    }
}

}

int main(){
int n,e;
cin>>n>>e;
vector<int>vis(n,0);
vector<int>dist(n,1e9);
vector<vector<pair<int,int>>>adj(n);
for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
}
dijkstra(adj,vis,dist,0);
for(int i=0;i<n;i++){
    cout<<dist[i];
}
return 0;
}
