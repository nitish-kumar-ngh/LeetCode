class Solution {
public:
   long long int f( vector<int>&v,int n,int idx,int mx,int k){
        if(n==0 && k>=2 )return 1;
        if(idx>=n)return -1e8;
       long long  int ans=INT_MIN;
        ans=max(ans ,v[idx]* f(v,n-v[idx],idx,mx,k+1));
        ans =max(ans , f(v,n,idx+1,mx,k));
        return ans;
    }
    int integerBreak(int n) {
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
           v[i]=i+1;
        }
       return f(v,n,0,0,0);
    }
};