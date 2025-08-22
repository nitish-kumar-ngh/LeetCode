class Solution {
public:
    int t[31][1001];
    int mod = 1000000007;
    long long f(int n, int k, int target){
        if(n==0 && target==0)return 1;
        if(n==0 || target<=0)return 0;
        if(t[n][target]!=-1)return t[n][target];
        long long ans =0;
        for(int i=1;i<=k;i++){
     ans=(ans %mod + f(n-1,k,target-i)%mod)%mod;
        }
        return t[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(t,-1,sizeof(t));
     return  f(n,k,target); 
    }
};