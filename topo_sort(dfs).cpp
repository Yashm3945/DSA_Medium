#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj,vector<int>&vis,stack<int>&st,int src){
vis[src]=1;
for( auto it: adj[src]){
    if(vis[it]==0){
        dfs(adj,vis,st,it);
    }
}
st.push(src);
}

int main(){
int n,e;
cin>>n>>e;
vector<vector<int>>adj(n);
for(int i=0;i<e;i++){
    int u,v;
    cin>>u;
    cin>>v;
    adj[u].push_back(v);
}
vector<int>vis(n,0);
stack<int>st;
for(int i=0;i<n;i++){
    if(vis[i]==0){
        dfs(adj,vis,st,i);
    }
}
while(!st.empty()){
    cout<<st.top();
    st.pop();
}
return 0;
}
