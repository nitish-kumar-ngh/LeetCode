class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
       long long int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]-i;
        }
        for (int i=1;i<nums.size();i++){
            
            mp[nums[i-1]]++;
            cnt+=i-mp[nums[i]];
        }
          
            
         return cnt;
    }
};