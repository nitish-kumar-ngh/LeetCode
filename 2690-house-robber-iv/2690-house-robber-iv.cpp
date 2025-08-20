class Solution {
public:
  int t[100005];
    int f(vector<int>& nums,int mid,int idx){
        if(idx>=nums.size())return 0;
        int ans =0;
        if(t[idx]!=-1)return t[idx];
        if(nums[idx]<=mid){
         ans=ans+max(1+f(nums,mid,idx+2),f(nums,mid,idx+1));
        }else{
            ans+=f(nums,mid,idx+1);
        }
   //     ans+=;
        return t[idx]=ans;
    }
    int p(vector<int>& nums, int k,int mid){
        memset(t,-1,sizeof(t));
        int cnt =0;
       cnt = f(nums,mid,0);
        if(cnt>=k)return 1;
        else return 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = INT_MAX;
        int right = INT_MIN;
        for(int i=0;i<nums.size();i++){
            left=min(left,nums[i]);
            right=max(right,nums[i]);
        }
        int ans=INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(p(nums,k,mid)==0)left=mid+1;
            else {
                 
                right=mid-1;
                ans=min(ans,right);
              
                }
        }
       // cout<<f(nums,1,0);
        return ans+1;
    }
};