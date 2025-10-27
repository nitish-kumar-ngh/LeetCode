class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();
     vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                int x=0;
                int nr = i-k;
                if(nr<0)nr =0;
                int nc=j-k;
                if(nc<0)nc =0;
                int NR= i+k;
                if(NR>=r) NR=r-1;
                int NC= j+k;
                if(NC>=c)NC=c-1;
                for(int k=nr;k<=NR;k++){
                   for(int l=nc;l<=NC;l++){
                       x+=mat[k][l];
                   }
                }
                ans[i][j] = x;
                
            }
        }
        return ans;

    }
};