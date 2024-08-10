class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute force
        int maxf=0;
        int changes=0;
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            int hash[26]={0};
            for (int j=i;j<s.size();j++){
                hash[s[j]-'A']++;
                maxf=max(maxf,hash[s[j]-'A']);
                changes=(j-i+1)-maxf;
                if (changes<=k){
                    maxlen=max(maxlen,j-i+1);

                }else break;
            }
        }
        return maxlen;
    }
};