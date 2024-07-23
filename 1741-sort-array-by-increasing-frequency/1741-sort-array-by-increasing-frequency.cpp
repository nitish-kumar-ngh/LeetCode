class Solution {
public:
  
    vector<int> frequencySort(vector<int>& nums) {
         auto alpha=[&](pair<int, int>& a, pair<int, int>& b) {
        if (a.second==b.second) return a.first>b.first;
        else return a.second < b.second;
        };
        unordered_map<int, int >mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int> >p(mp.begin(),mp.end());
        sort(p.begin(), p.end(),alpha);
        vector<int>e;
        for (auto v:p){
          for (int i=0;i<v.second;i++){
               e.push_back(v.first);
          }
        }

  return e;
    }
};