class Solution {
public:
     int t[10001][101];
    int f(int n,int idx,vector<int>&v){
    
    if(n==0)return 0;
    if(n<0)return 1e8;
     if(idx>=101)return 1e8;
     if(t[n][idx]!=-1)return t[n][idx];
    int ans = INT_MAX;
    ans=min(ans,1+f(n-v[idx],idx,v));
    ans=min(ans,f(n,idx+1,v));
    return t[n][idx]=ans;
    }
    int numSquares(int n) {
        memset(t,-1,sizeof(t));
     vector<int>v(101,0);
     for(int i=1;i<=100;i++){
        v[i]= i*i;
     }
     return f(n,1,v);
    }
};