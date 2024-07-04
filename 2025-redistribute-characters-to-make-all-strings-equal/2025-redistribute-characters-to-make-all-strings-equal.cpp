class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        if(n==1)return true;
        unordered_map<char,int>mp;
        for (auto word:words){
            for (char ch:word){
                mp[ch]++;
            }
        }
        for (auto ele:mp){
            int freq=ele.second;
            if (freq % n !=0)return false;
        }
        return true;
    }
};