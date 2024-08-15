class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //map -> char index
        unordered_map<char,int>mp;
        int l=0;
        int r=0;
        int len=0;
        while(r<s.size()){
          
          if (mp.find(s[r])!= mp.end()){
            if(mp[s[r]]>=l)l=1+mp[s[r]];
          }
          len= max(len,r-l+1);
          mp[s[r]]=r;
          r++;
    }
    return len;
    }
};