class Solution {
public:
    int T[105][10005];
    int f(string s, string t,int i,int j){
        if(i>=s.size()|| j>=t.size())return 0;
        if(T[i][j]!=-1)return T[i][j];
        int ans= INT_MIN;
        if(s[i]==t[j]){
              ans=max(ans,1+f(s,t,i+1,j+1));
        }else{
            ans=max({ans,f(s,t,i+1,j),f(s,t,i,j+1)});
        }
        return T[i][j]=ans;
    }
    bool isSubsequence(string s, string t) {
        memset(T,-1,sizeof(T));
       return s.size()== f(s,t,0,0);
    }
};