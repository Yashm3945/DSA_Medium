class Solution {
public:
    void bfs(vector<vector<int>>& image,int sr, int sc, int color){
        int n=image.size();
        int m=image[0].size();
        int prev=image[sr][sc];
        if(prev == color) return;   
        image[sr][sc]=color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<int>p1={0,0,-1,1};
        vector<int>p2={-1,1,0,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int a=x+p1[i];
                int b=y+p2[i];
                if(a>=0&&a<n && b>=0&&b<m){
                    if(image[a][b]==prev){
                        image[a][b]=color;
                        q.push({a,b});
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        bfs(image,sr,sc,color);
        return image;
    }
};