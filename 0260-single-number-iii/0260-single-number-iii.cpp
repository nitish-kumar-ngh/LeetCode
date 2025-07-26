class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0;
        for(int i=0;i<nums.size();i++){
            a=a^nums[i];
        }
        int last;
        for(int i=0;i<32;i++){
            if(a & 1<<i){
                last =i;
                break;
            }
        }
        int b=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]&1<<last){
                b=b^nums[i];
             }else{
                  c=c^nums[i];  
             }
        }
        return {b,c};
    }
};