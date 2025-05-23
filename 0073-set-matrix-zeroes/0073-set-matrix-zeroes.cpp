class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>R(row,0);
        vector<int>C(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if (matrix[i][j]==0){
                    R[i]=1;
                    C[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            if (R[i]==1){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
           for(int i=0;i<col;i++){
            if (C[i]==1){
                for(int j=0;j<row;j++){
                    matrix[j][i]=0;
                }
            }
        }
       
    }
};