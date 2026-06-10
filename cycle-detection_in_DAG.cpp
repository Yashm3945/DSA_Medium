#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&adj,int n,int src,vector<int>&vis,vector<int>&pathvis){
vis[src]=1;
pathvis[src]=1;
for(auto it: adj[src]){
    int node=it;
    if(vis[it]==0&&pathvis[it]==0){
        if(dfs(adj,n,it,vis,pathvis)==true){
            return true;
        }
    }
    else if(vis[it]==1&&pathvis[it]==0){
        return false;
    }
    else {
        return true;
    }
}
pathvis[src]=0;
//not come here
return true;
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
}
cout<<"enter";
int src;
cin>>src;
vector<int>vis(n);
vector<int>pathvis(n);
cout<<dfs(adj, n, src,vis,pathvis);
}

