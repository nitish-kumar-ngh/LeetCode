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
        memset(t,-1,sizeof(t));
        return f(0,-1,nums);
    }
};