class Solution {
public:
 int f(vector<int>& nums, int sum){
    int k=1;
    int sumsplit=0;
    for (int i=0;i<nums.size();i++){
        if (sumsplit+nums[i]<=sum){
          sumsplit+=nums[i];
        }else{
            sumsplit=nums[i];
            k++;
        }
    }
    return k;
 }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int mn=INT_MIN;
        for (int i=0;i<nums.size();i++){
            s+=nums[i];
            mn=max(mn,nums[i]);
        }
        int ans=INT_MAX;
        int low=mn;
        int high=s;
        while(low<=high){
            int mid=(low+high)/2;
            if (f(nums,mid)>k){
              if (f(nums,mid)==k)  ans=min(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;

    }
};