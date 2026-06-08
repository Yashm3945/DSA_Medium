#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>&adj,vector<int>&vis,vector<int>indegree,int n){
    queue<int>q;
    vector<int>ans;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        vis[i]=1;
        q.push(i);
}
}
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it :adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
                vis[it]=1;
            }
        }
    }
return ans;
}
int main(){
int n,e;
cin>>n>>e;
vector<vector<int>>adj(n);
vector<int>indegree(n);
for(int i=0;i<e;i++){
    int u,v;
    cin>>u;
    cin>>v;
    adj[u].push_back(v);
    indegree[v]++;
}
vector<int>vis(n,0);
vector<int>ans=bfs(adj,vis,indegree,n);
for(int i=0;i<ans.size();i++){
    cout<<ans[i];
}
return 0;
}
