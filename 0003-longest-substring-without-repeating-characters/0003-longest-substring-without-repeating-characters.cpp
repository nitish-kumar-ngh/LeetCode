class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0;
        int n=s.size();
        int r=0;
        int maxlen =0;
        while(r<n){
           if (mp.find(s[r])==mp.end()){
               mp[s[r]]++;
           }else{
            while(mp[s[r]]>0){
                mp[s[l]]--;
                l++;
                if (mp[s[r]]==0)mp.erase(s[r]);
            }
            mp[s[r]]++;
           }
           maxlen=max(maxlen,r-l+1);
           r++;
            







        }
        return maxlen;
        

    }
};