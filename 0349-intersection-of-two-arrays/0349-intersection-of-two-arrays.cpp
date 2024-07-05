class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for (int &num:nums1){
            mp[num]++;
        }
        unordered_set<int>set;
        for (auto ele:nums2){
           if (mp.find(ele)!=mp.end())set.insert(ele);
        }
       vector<int>v;
      for (auto e:set){
        v.push_back(e);
      }
      return v;
    }
};