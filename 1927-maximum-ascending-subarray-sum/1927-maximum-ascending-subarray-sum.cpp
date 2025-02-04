class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx=0;
        for (int i=0;i<nums.size();i++){
              int s=nums[i];
            for (int j=i+1;j<nums.size();j++){
               
                if (nums[j]>nums[j-1]){
                    s+=nums[j];
                }else{
                    mx=max(mx,s);
                    break;
                }
                 
            }
             mx=max(mx,s);
        }
        return mx;
    }
};