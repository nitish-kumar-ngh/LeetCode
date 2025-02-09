class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
            unordered_map<int,int>mp1;
            for(auto v:mp){
                mp1[v.second]++;

            }
            for(auto x:mp1){
                if(x.second>1)return false;
            }
            return true;
    }
};