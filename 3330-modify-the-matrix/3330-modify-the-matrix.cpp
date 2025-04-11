class Solution {
public:
  int solve(vector<vector<int>>& matrix,int col,int m,int n){
    int mx=INT_MIN;
    for(int i=0;i<m;i++){
        mx=max(mx,matrix[i][col]);
    }
    return mx;

  }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (matrix[i][j]==-1){
                    int d=solve(matrix,j,m,n);
                    ans[i][j]=d;
                }else{
                      ans[i][j]=matrix[i][j];
                }
            }
        }
        return ans;
    }
};