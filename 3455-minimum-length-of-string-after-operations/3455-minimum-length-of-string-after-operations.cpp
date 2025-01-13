class Solution {
public:
    int minimumLength(string s) {
         
        int ans=s.size();
        unordered_map<char,int>mp;
        for (char ch:s){
            mp[ch]++;
        }
        for (auto v:mp){
            int freq=v.second;
            if (freq>=3){
              if (freq %2 !=0)ans=ans-(freq-1);
              else ans=ans-(freq-2);


        }}
        return ans;
    }
};