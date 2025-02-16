class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int mxfreq=0;
        int mxlen=0;
        unordered_map<char,int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            mxfreq=max(mxfreq,mp[s[r]]);
            if(r-l+1-mxfreq>k){
                mp[s[l]]--;
                 mxfreq=max(mxfreq,mp[s[l]]);
                 l++;
            }
            mxlen=max(mxlen,r-l+1);
            r++;
        }
        return mxlen;
    }
};