class Solution {
public:
int T[201][20001];
    bool f(vector<int>& nums,int t,int idx){
        if(t<0)return false;
        if(t==0)return true;
        if(idx>=nums.size())return false;
        if(T[idx][t]!=-1)return T[idx][t];
        return T[idx][t]=f(nums,t-nums[idx],idx+1)|| f(nums,t,idx+1);
    }
    bool canPartition(vector<int>& nums) {
        memset(T,-1,sizeof(T));
        
        int s =0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2!=0)return false;
        return f(nums,s/2,0);
    }
};