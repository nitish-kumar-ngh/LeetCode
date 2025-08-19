class Solution {
public:
   int t1[1001][1001];
     int f(string &s,string &t,int i1,int i2){
        if(i1>=s.size() || i2>=s.size())return t1[i1][i2]= 0;
        int ans=INT_MIN;
        if( t1[i1][i2]!=-1)return  t1[i1][i2];
        if(s[i1]==t[i2]){
     // ans+=1+f(s,t,i1+1,i2+1);
     ans=max(ans,1+f(s,t,i1+1,i2+1));
        }else{
           // ans=ans+max(f(s,t,i1+1,i2),f(s,t,i1,i2+1));
           ans=max(ans,max(f(s,t,i1+1,i2),f(s,t,i1,i2+1)));
        }
        return  t1[i1][i2]=ans;
     }
    int longestPalindromeSubseq(string s) {
        memset(t1,-1,sizeof(t1));
        string t=s;
         reverse(t.begin(),t.end());
        return f(s,t,0,0);
    }
};