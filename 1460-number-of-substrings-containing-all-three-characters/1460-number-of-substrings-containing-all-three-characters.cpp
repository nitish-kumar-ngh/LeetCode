class Solution {
public:
    int f(string s,int k){
        int ans=0;
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp.size()>k){
               mp[s[l]]--;
               if(mp[s[l]]==0)mp.erase(s[l]);
               l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
         return f(s,3)-f(s,2);
    }
};