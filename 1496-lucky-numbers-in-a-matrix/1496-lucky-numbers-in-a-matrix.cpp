class Solution {
public:
   int maxicol(vector<vector<int>>& matrix,int j,int row){
    int maxi=INT_MIN;
    for (int k=0;k<row;k++){
        maxi=max(maxi,matrix[k][j]);
    }
    return maxi;
   }
     int minirow(vector<vector<int>>& matrix,int i,int col){
    int maxi=INT_MAX;
    for (int k=0;k<col;k++){
        maxi=min(maxi,matrix[i][k]);
    }
    return maxi;
   }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>result;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                int x = maxicol(matrix,j,row);
                int y= minirow(matrix,i,col);
                if (x==y)result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};