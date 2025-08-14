class Solution {
public:
    int t[2001];
    bool p(string &k){
        int l=0;
        int r=k.size()-1;
        while(l<r){
            if(k[l]!=k[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int f(string &s,int idx){
        if(idx>=s.size())return t[idx]=0;
        int ans=INT_MAX;
        if(t[idx]!=-1)return t[idx];
          string k="";
        for(int i=idx;i<s.size();i++){
          // = s.substr(idx,i-idx+1);
          k+=s[i];
            if(p(k)){
             ans=min(ans,1+f(s,i+1));
            }
        }
        return t[idx] = ans;
    }
    int minCut(string s) {
        memset(t,-1,sizeof(t));
        return f(s,0)-1;
    }
};