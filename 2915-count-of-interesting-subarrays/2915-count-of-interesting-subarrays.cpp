class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        for(int i=0;i<nums.size();i++){
            if (nums[i]%modulo==k)nums[i]=1;
            else nums[i]=0;
        }
        unordered_map<long long int,long long int>mp;
       long long ans=0;
        long long sum =0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r1=sum%modulo;
            int r2 = (r1-k+modulo)%modulo;
            ans+=mp[r2];
            mp[r1]++;

        }
        return ans;
    }
};