class Solution {
public:
    
    vector<vector<string>>result;
    bool isSafe(int j,int i,int n,vector<vector<string>>&grid){
        for (int k=i-1;k>=0;k--){
            if (grid[k][j]=="Q")return false;
        }
        for (int k=i-1,m=j-1;k>=0 && m>=0;k--,m--){
            if (grid[k][m]=="Q")return false;
        }
        for (int k=i-1,m=j+1;k>=0&&m<n;k--,m++){
            if (grid[k][m]=="Q")return false;
        }
        return true;
    }
    void f(int n,int row,vector<vector<string>>&grid){
      if (row>=n){
         vector<string>temp;
        for (int i=0;i<n;i++){
           
            string s="";
            for(int j=0;j<n;j++){
                
                s=s+grid[i][j];
            }
            temp.push_back(s);
        }
        result.push_back(temp);
        return;
      }
      for (int i=0;i<n;i++){
       if(isSafe(i,row,n,grid)){
           grid[row][i]="Q";
           f(n,row+1,grid);
           grid[row][i]=".";
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>grid(n,vector<string>(n,"."));
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }cout<<"\n";
        }
       f(n,0,grid);
        return result;
    }
};