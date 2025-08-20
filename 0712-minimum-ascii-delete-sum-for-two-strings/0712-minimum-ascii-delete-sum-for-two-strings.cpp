class Solution {
public:
    int t[1001][1001];
    int f(string &s1, string &s2,int idx1,int idx2){
        if(idx1>=s1.size()&&idx2>=s2.size())return 0;
        if(idx1>=s1.size() ){
            return s2[idx2]+f(s1,s2,idx1,idx2+1);
        }
        if(idx2>=s2.size() ){
            return s1[idx1]+f(s1,s2,idx1+1,idx2);
        }
        if(t[idx1][idx2]!=-1)return t[idx1][idx2];
        int ans=INT_MAX;
        if(s1[idx1]==s2[idx2]){
            ans=min(ans,f(s1,s2,idx1+1,idx2+1));
        }else{
            ans=min(ans,min(s1[idx1]+f(s1,s2,idx1+1,idx2),s2[idx2]+f(s1,s2,idx1,idx2+1)));
        }
        return t[idx1][idx2]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
       return f(s1,s2,0,0);
    }
};