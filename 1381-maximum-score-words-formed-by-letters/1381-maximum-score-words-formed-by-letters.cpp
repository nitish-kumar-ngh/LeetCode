class Solution {
public:
    int f(vector<string>& words, unordered_map<char,int>&mp,vector<int>& score,int idx){
        if(idx>=words.size())return 0;
        int ans = INT_MIN;
        bool flag = true;
        for(auto ch:words[idx]){
            mp[ch]--;
            if(mp[ch]<0)flag=false;
        }
        for(auto ch:words[idx]){
            mp[ch]++;
           
        }
        if(flag==true){
            int a=0;
             for(auto ch:words[idx]){
                mp[ch]--;
              if(mp[ch]>=0) a+=score[ch-'a'];
            }
           
            ans=max(ans,a+f(words,mp,score,idx+1));
           for(auto ch:words[idx]){
                mp[ch]++;
            
            }
        }
         ans=max(ans,f(words,mp,score,idx+1));
         return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
       unordered_map<char,int>mp;
       for(auto v:letters){
        mp[v]++;
       }
      return  f(words,mp,score,0);
    }
};