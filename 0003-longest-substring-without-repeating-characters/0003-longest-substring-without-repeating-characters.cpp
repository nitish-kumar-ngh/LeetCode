class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        int lent = 0;
        while(r<s.size()){
          mp[s[r]]++;
          while (mp[s[r]]>1){
            mp[s[l]]--;
            l++;
          }
          lent=max(lent,r-l+1);
          r++;
        }
        return lent;
    }
};