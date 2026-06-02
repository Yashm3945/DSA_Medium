class Solution {
public:
int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,queue<pair<pair<int,int>,int>>q){
int n=grid.size();
int m=grid[0].size();
vector<int>arr1={0,0,1,-1};
vector<int>arr2={1,-1,0,0};

int t=0;

while(!q.empty()){
    int ii=q.front().first.first;
    int jj=q.front().first.second;
    int x=q.front().second;
    q.pop();
    t=max(x,t);
    for(int i=0;i<4;i++){
        int a=ii+arr1[i];
        int b=jj+arr2[i];
        if(a<n&&a>=0&&b<m&&b>=0){
            if(grid[a][b]==1&&vis[a][b]==0){
             vis[a][b]=2;
             q.push({{a,b},x+1});
            }
        }
    }
}
return t;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
                vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   q.push({{i,j},0});
                   vis[i][j]=2;
                }
            }
        }

        int x=bfs(grid,vis,q);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return x;
    }
};