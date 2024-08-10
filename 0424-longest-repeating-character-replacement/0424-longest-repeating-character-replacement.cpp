class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute force
        // int maxf=0;
        // int changes=0;
        // int maxlen=0;
        // for(int i=0;i<s.size();i++){
        //     int hash[26]={0};
        //     for (int j=i;j<s.size();j++){
        //         hash[s[j]-'A']++;
        //         maxf=max(maxf,hash[s[j]-'A']);
        //         changes=(j-i+1)-maxf;
        //         if (changes<=k){
        //             maxlen=max(maxlen,j-i+1);

        //         }else break;
        //     }
        // }
        // return maxlen;
        int l=0;int r=0;int maxf=0;int maxlen=0;
        int hash[26]={0};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxf=max(maxf,hash[s[r]-'A']);
            if ((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                l++;
            }
              if ((r-l+1)-maxf<=k){
               maxlen=max(maxlen,r-l+1);
            }
          r++;
        }
        return maxlen;
    }
};