class Solution {
public:
bool fun(vector<vector<int>>& adj,vector<int>&vis,vector<int>&coll,int src ,int col ){
    queue<pair<int,int>>q;
    q.push({src,0});
    coll[src]=col;
    vis[src]=1;
    while(!q.empty()){
        int node=q.front().first;
        int c=q.front().second;
        q.pop();
        for(auto it:adj[node]){
           if(vis[it]==0){
            coll[it]=!c;
            q.push({it,!c});
            vis[it]=1;
           }
           else if(vis[it]!=0){
           if(coll[it]==c){
            return false;
           }
           }
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>coll(n,0);
       vector<int>vis(n,0);
       for(int i=0;i<n;i++){
        if(vis[i]==0){
           if(fun(graph,vis,coll,i,0)==false){
            return false;
           }
        }
       }
       return true;
    }
};