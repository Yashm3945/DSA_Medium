#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&adj,int n,int src){
vector<int>vis(n,0);
queue<int>q;
q.push(src);
vis[src]=1;
while(!q.empty()){
    int node=q.front();
    q.pop();
    cout<<node;
    for(auto it: adj[node]){
        if(vis[it]==0){
        q.push(it);
        vis[it]=1;
            }
    }
}
}

int main(){
int e,n;
cin>>n>>e;
vector<vector<int>>adj(n);
for(int i=0;i<e;i++){
    cout<<"enter u,v";
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
cout<<"enter";
int src;
cin>>src;

bfs(adj, n, src);
}
