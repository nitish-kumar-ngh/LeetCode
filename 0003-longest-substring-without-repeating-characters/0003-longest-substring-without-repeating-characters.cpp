class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int right=0;
        int ans=0;
        unordered_map<char,int>mp;
        while (right<s.size()){
           //condition
           mp[s[right]]++;
           if (mp[s[right]]<1){
            right++;
           }else if (mp[s[right]]==1){
            ans=max(ans,right-low+1);
            right++;
           }else{
            while(mp[s[right]]>1){
                mp[s[low]]--;
                low++;
            }
            right++;
           }
        }
        return ans;
    }
};