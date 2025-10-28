class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int  l =0;
        int r =0;
        unordered_set<int>s;
        for(int i =0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int cnt =0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
           mp[nums[r]]++;
           while(mp.size()==s.size()){
            cnt = cnt + nums.size()-r;
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            l++;
             
           }
           r++;
        }
        return cnt;
    }
};