class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]++;
        }
        int cnt=0;
        int ans=0;
        for (auto word:words){
            cnt=0;
            for(char ch:word){
                if (mp[ch]>0){
                    cnt++;
                    mp[ch]--;
                }

            }
            if (cnt==word.size())ans+=cnt;
            for(int i=0;i<chars.size();i++){
            mp[chars[i]]=0;
        }
           for(int i=0;i<chars.size();i++){
            mp[chars[i]]++;
        }
        }
        return ans;
    }
};