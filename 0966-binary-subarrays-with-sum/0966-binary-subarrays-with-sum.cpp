class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int presum=0;
        map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int remove=presum-goal;
            cnt+=mp[remove];
            mp[presum]++;
        }
        return cnt;
    }
};