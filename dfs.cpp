#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,int n,int src,vector<int>&vis){
vis[src]=1;
cout<< src;
for(auto it: adj[src]){
    if(vis[it]==0){
        dfs(adj,n,it,vis);
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
vector<int>vis(n);
dfs(adj, n, src,vis);
}
