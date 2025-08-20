class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int dp[100001];
        int b=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                dp[i+1]=min(dp[i]+1,b);
            }else{
                dp[i+1]=dp[i];
                b++;
            }
        }
        return dp[n];
    }
};