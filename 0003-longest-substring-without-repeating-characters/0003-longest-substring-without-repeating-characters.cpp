class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mxlen=0;
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        while(r<s.size()){
             mp[s[r]]++;
             while(mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
             }
             mxlen=max(mxlen,r-l+1);
             r++;
        }
        return mxlen;
    }
};