class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int x,int y){
      int n=grid.size();
      int m=grid[0].size();
      vis[x][y]=1;
      queue<pair<int,int>>q;
      q.push({x,y});
      vector<int>a1={1,-1,0,0};
      vector<int>a2={0,0,1,-1};
      while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int u=i+a1[k];
            int v=j+a2[k];
            if(u<n&&u>=0 && v<m&&v>=0){
                if(grid[u][v]=='1'&&vis[u][v]==0){
                    q.push({u,v});
                    vis[u][v]=1;
                }
            }
        }
      }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
         int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'&&vis[i][j]==0){
                count++;
              bfs(grid,vis,i,j);
            }
        }
      }
      return count;

    }
};