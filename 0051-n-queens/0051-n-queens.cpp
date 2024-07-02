class Solution {
public:
     vector<vector<char>>grid;
     vector<vector<string>>result;
     bool canSafeQueen(int row,int col,int n){
        //row attack
         for (int i=row-1;i>=0;i--){
            if (grid[i][col]=='Q') return false;
         }
         //left diagonal check
          for (int i=row-1, j=col-1;i>=0 and j>=0;i--,j--){
            if (grid[i][j]=='Q') return false;
         }
         //right digonal check
         for (int i=row-1,j=col+1;i>=0 and j<n;i--,j++){
            if (grid[i][j]=='Q') return false;
         }
         return true;

     }
     void f(int row,int n){
        if (row==n){
            vector<string>temp;
            for (int i=0;i<n;i++){
                
                string ans="";
                for (int j=0;j<n;j++){
                    ans=ans+grid[i][j];
                }
                temp.push_back(ans);
            }
            result.push_back(temp);
            return;

        }
            
                for (int col=0;col<n;col++){
                    if (canSafeQueen(row,col,n)){
                        grid[row][col]='Q';
                        f(row+1,n);
                        grid[row][col]='.';
                        
                    }
                }
            
        


     }
    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        result.clear();
        grid.resize(n,vector<char>(n,'.'));
         f(0,n);
         return result;
    }
};