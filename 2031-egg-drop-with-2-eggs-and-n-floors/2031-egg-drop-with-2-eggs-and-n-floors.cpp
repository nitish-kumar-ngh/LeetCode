class Solution {
public:
      int dp[101][10005];
    int f(int e,int n){
        if(e==1)return dp[e][n]=n;
        if(n==0 || n==1)return dp[e][n]= n;
        if(dp[e][n]!=-1)return dp[e][n];
        int anw=INT_MAX;
        for(int k=1;k<=n;k++){
            int ans=1+max(f(e,n-k),f(e-1,k-1));
            anw=min(anw,ans);
        }
        return dp[e][n]=anw;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
      return   f(2,n);
    }
};