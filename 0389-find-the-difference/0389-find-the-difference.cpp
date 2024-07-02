class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp;
        for (int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
         for (int i=0;i<t.size();i++){
            mp1[t[i]]++;
        }
        for (auto ele:mp1){
            char ch=ele.first;
            if(mp1[ch]!=mp[ch]) return ch;
        }
        return -1;
    }
};