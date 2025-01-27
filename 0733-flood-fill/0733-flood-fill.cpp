class Solution {
public:
int m,n,p;
void dfs( int sr, int sc,int color,vector<vector<int>>& image,vector<vector<int>>&vis){
vis[sr][sc]=1;
image[sr][sc]=color;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
for(int i=0;i<4;i++){
    int newx=sr+dx[i];
    int newy=sc+dy[i];
    if (newx>=0 && newy>=0 && newx<m && newy<n && vis[newx][newy]==0&&image[newx][newy]==p){
        dfs(newx,newy,color,image,vis);
    }
}
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         m=image.size();
         n=image[0].size();
         p=image[sr][sc];
        vector<vector<int>>vis(m,vector<int>(n,0));
        dfs(sr,sc,color,image,vis);
        return image;
    }
};