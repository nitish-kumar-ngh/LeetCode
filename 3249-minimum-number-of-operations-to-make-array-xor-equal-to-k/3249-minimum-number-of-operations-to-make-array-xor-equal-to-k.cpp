class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>v(32,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i]&1<<j)v[j]++;
            }
        }
        int cnt =0;
         for(int i=0;i<32;i++){
            if(k & 1<<i){
                if(v[i]%2==0)cnt++;
            }else{
                if(v[i]%2!=0)cnt++;
            }
         }
         return cnt;
        
    }
};