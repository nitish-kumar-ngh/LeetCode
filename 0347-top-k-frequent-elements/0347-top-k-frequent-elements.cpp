class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
         vector<int> top;
         priority_queue<pair<int,int>>p;

         for(auto v:mp){
           // if(v.second>=k)top.push_back(v.first);
           p.push({v.second,v.first});
         }
         while(p.size()>0 && k>0){
            auto x=p.top();
            p.pop();
            top.push_back(x.second);
            k--;

         }
         return top;
    }
};