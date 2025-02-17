class Solution {
public:
 int f(vector<int>& nums,int k){
    int ans=0;
    int l=0;
    int r=0;
    int s=0;
    while(r<nums.size()){
          s+=nums[r];
          while(s>k){
            s=s-nums[l];
            l++;
          }
          ans+=r-l+1;
          r++;
    }
    return ans;
 }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0)nums[i]=1;
            else nums[i]=0;
        }
        return f(nums,k)-f(nums,k-1);

    }
};