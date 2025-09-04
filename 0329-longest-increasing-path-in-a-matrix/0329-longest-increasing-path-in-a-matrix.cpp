class Solution {
public:
    int t[201][201];
    int r;
    int c;
    int lip(vector<vector<int>>& matrix,int i,int j){
        if(i>=r ||j>=c ||i<0 ||j<0)return 0;
        if(t[i][j]>0)return t[i][j];
        int ans =1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        for(int d=0;d<4;d++){
            int x=i+dx[d];
            int y = j+dy[d];
            if(x>=0 && x<r&&y>=0 && y<c&&matrix[x][y]>matrix[i][j]){
                  ans=max(ans,1+lip(matrix,x,y));
            }
           
        }
        t[i][j]=ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(t,0,sizeof(t));
        r = matrix.size();
        c = matrix[0].size();
        int ans =1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
         ans=max(ans,lip(matrix,i,j));
            }
        }
        return ans;
    }
};