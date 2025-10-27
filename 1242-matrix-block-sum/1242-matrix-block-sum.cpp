class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c=  mat[0].size();
        vector<vector<int>>prefix(r,vector<int>(c,0));
        vector<vector<int>>ans(r,vector<int>(c,0));
        prefix[0][0]=mat[0][0];
        for(int i=1;i<r;i++)prefix[i][0] = prefix[i-1][0]+mat[i][0];
        for(int i=1;i<c;i++)prefix[0][i] = prefix[0][i-1]+mat[0][i];
        for(int i=1;i<r;i++){
            for(int j =1;j<c;j++){
                prefix[i][j] = mat[i][j] +prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }

        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
             //   prefix[i][j] = mat[i][j] +prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
          int r1 = max(0, i - k);
int c1 = max(0, j - k);

             int r2 = min(r-1,i+k);
             int c2 = min(c-1,j+k);
             
             
             
          ans[i][j] = prefix[r2][c2]
           - (c1 > 0 ? prefix[r2][c1 - 1] : 0)
           - (r1 > 0 ? prefix[r1 - 1][c2] : 0)
           + (r1 > 0 && c1 > 0 ? prefix[r1 - 1][c1 - 1] : 0);

            }
        }
        return ans;
    }
};