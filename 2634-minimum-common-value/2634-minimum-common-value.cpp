class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for (int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }

        for (int i=0;i<nums2.size();i++){
            if (mp.find(nums2[i]) !=mp.end()){
                return nums2[i];
            }
        }
        return -1;
    }
};