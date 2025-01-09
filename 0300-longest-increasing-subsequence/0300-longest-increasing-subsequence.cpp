class Solution {
public:
//int len=INT_MIN;
    int t[2505][2505];
    int f(int idx,int prev_idx,vector<int>& nums){
        if (idx>=nums.size())return 0;
        if (t[idx][prev_idx+1]!=-1)return t[idx][prev_idx+1];

        int len=f(idx+1,prev_idx,nums);
        if (prev_idx==-1||nums[idx]>nums[prev_idx]){
           len=max(len,1+f(idx+1,idx,nums));
        }
        return t[idx][prev_idx+1]=len;
        
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         int dp[2505][2505];
        memset(dp,0,sizeof(dp));
      //  return f(0,-1,nums);
      for (int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int len=dp[i+1][j+1];
        if (j==-1||nums[i]>nums[j]){
           len=max(len,1+dp[i+1][i+1]);
         
        }
          dp[i][j+1]=len;
        }
      }
      for (int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
      }
      return dp[0][-1+1];
    }
};