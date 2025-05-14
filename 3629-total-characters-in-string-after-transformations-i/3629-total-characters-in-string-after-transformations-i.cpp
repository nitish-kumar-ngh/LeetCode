class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
       // unordered_map<char,long long>mp;
       vector<int>mp(26,0);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
         int MOD = 1e9 + 7;
        
        for(int i=1;i<=t;i++){
          //  unordered_map<char,long long>temp;
           vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                char ch=i+'a';
                int freq=mp[i];
                if (ch!='z'){
                    temp[ch+1-'a']= (temp[ch+1-'a']+freq)%MOD;

                }else{
                    temp['a'-'a']=(temp['a'-'a']+freq)%MOD;
                     temp['b'-'a']=(temp['b'-'a']+freq)%MOD;
                }
            }
            mp=temp;
        }
        int ans =0;
        for(int i=0;i<26;i++){
            ans=(ans+mp[i])%MOD;
        }
        return ans;
    }
};