class Solution {
public:
    int dp[101];
    int f(string s,int i){
        if(i>=s.size())return 1;
        int ans =0;
         if (dp[i] != -1) return dp[i];
        if(s[i]!='0'){
            ans =ans+ f(s,i+1);
        }
       
        if(i+1<s.size() && s[i]!='0'){
            if(stoi(s.substr(i,2))<=26){
                 ans=ans+f(s,i+2);
            }
            
        }
        return  dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
       return f(s,0);
    }
};