class Solution {
public:
    vector<int>arr;
    vector<int>dp;
    int f(int i){
        if (i==0)return 1;
        if (dp[i]!=-1) return dp[i];
        int mx=INT_MIN;
        for (int j=0;j<=i-1;j++){
            if (arr[j]<arr[i])
            mx= max(mx,f(j));
        }
        if (mx==INT_MIN)return dp[i]=1;
        return dp[i]= 1+mx;
    }
    int lengthOfLIS(vector<int>& nums) {
    arr=nums;
    dp.resize(2505,-1);
    int ans=INT_MIN;
    dp[0]=1;
    for (int i=0;i<arr.size();i++){
        ans=max(ans,f(i));
    }
    return ans;
    }
};