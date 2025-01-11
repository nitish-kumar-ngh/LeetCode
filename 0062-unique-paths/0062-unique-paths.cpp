class Solution {
public:
  int t[105][105];
   int f(int i,int j,int m,int n){
    if(i>=m || j>=n){
        return 0;
    }
    if (i==m-1 && j==n-1)return 1;
    if(t[i][j]!=-1)return t[i][j];
    int down=f(i+1,j,m,n);
    int right=f(i,j+1,m,n);
    return t[i][j]= down+right;
   }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return f(0,0,m,n);
    }
};