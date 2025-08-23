class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                dp[i]=1+dp[i-1];
            }else dp[i]=1;
        }
        long long sum =0;
        for(int i=0;i<n;i++){
            sum=sum + dp[i];
        }
        return sum;
    }
};