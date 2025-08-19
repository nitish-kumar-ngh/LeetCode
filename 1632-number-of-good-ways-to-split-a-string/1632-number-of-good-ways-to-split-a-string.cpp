class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
       int cnt =0;
        for(int i=0;i<s.size();i++){
            mp2[s[i]]++;
        }

         for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
            mp2[s[i]]--;
            if(mp2[s[i]]==0)mp2.erase(s[i]);
            if(mp1.size()==mp2.size())cnt++;
        }
        return cnt;
    }
};