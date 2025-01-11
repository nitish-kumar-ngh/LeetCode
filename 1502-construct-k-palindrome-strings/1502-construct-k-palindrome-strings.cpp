class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int oddcnt=0;
        for(auto v:mp){
            int a=v.second;
            if(a%2!=0)oddcnt++;
        }
        return oddcnt<=k;
    }
};