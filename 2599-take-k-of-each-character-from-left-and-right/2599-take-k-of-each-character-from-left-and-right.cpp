class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int>mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
         if(mp['a']<k || mp['b']<k || mp['c']<k )return -1;
        int i =0;
        int j =0;
        int ans =0;
        while(j<s.size()){
            mp[s[j]]--;
            while( i <s.size() && (mp['a']<k || mp['b']<k || mp['c']<k)){
                mp[s[i]]++;
                i++;
            }
            ans= max(ans,j-i+1);
            j++;
        }
        return s.size()-ans;
    }
};