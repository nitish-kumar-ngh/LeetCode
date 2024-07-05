class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=1;
        for (auto ele:mp){
          int freq=ele.second;
          maxi=max(maxi,freq);
        }
        int cnt=0;
        for (auto ele:mp){
          int freq=ele.second;
           if (maxi==freq){
            cnt=cnt+freq;
           }
        }
        return cnt;
    }
};