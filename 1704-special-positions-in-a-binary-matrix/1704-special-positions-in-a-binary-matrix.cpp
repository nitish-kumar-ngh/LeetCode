class Solution {
public:
    int rowSum(int n,int col,vector<vector<int>>& mat){
        int sum=0;
        for(int i=0;i<col;i++){
            sum=sum+mat[n][i];
        }
        return sum;

    }
      int cowSum(int n,int row,vector<vector<int>>& mat){
        int sum=0;
        for(int i=0;i<row;i++){
            sum=sum+mat[i][n];
        }
        return sum;

    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        int row=mat.size();
        int col=mat[0].size();
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (mat[i][j]==1 && (rowSum(i,col,mat)==1 && cowSum(j,row,mat)==1)) cnt++;
            }
        }
        return cnt;
    }
};