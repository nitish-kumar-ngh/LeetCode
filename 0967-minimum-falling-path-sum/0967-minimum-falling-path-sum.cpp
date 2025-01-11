class Solution {
public:
int m,n;
int t[105][105];
    // int f(int i,int j,vector<vector<int>>& matrix){
    //     if(i>=m ||i<0 ||j>=n||j<0)return INT_MAX;
    //     if (i==m-1 && j<n && j>=0)return matrix[i][j];
    //     if (t[i][j]!=-1)return t[i][j];
    //     return t[i][j]= matrix[i][j]+min(f(i+1,j,matrix),min(f(i+1,j+1,matrix),f(i+1,j-1,matrix)));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       m=matrix.size();
         n=matrix[0].size();
        int ans=INT_MAX;
        memset(t,1e9,sizeof(t));
        //base case
        for(int i=0;i<n;i++){
            t[m-1][i]=matrix[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int a=1e9,b=1e9,c=1e9;
                if (j+1<n){
                      a=matrix[i][j]+t[i+1][j+1];
                }
                if (j-1>=0){
                    b=matrix[i][j]+t[i+1][j-1];
                }
                c=matrix[i][j]+t[i+1][j];
                 //t[i][j]= matrix[i][j]+min(t[i+1][j],min(t[i+1][j+1],t[i+1][j-1]));
                 t[i][j]=min(a,min(b,c));
            }
        }


        for(int i=0;i<n;i++){
            ans=min(ans,t[0][i]);
        }
        return ans;
    }
};