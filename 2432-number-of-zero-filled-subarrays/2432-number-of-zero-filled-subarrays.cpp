class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int j=i;
                int cnt =0;
                while(j<nums.size()&&nums[j]==0){
                 cnt++;
                 j++;
                }
                i=j;
                ans=ans+(long long )(cnt)*(cnt+1)/2;
            }
            
        }
        return ans;
    }
};