class Solution {
public:
 int mod = 1000000007;
 int t[1001];
    int f(int day,int delay,int forgot,int n){
        long long ans=0;
        if(t[day]!=-1)return t[day];
        ans++;
        if(day+forgot<=n)ans--;
        for(int i=day+delay;i<min(day+forgot,n+1);i++){
            ans+=f(i,delay,forgot,n);
            ans=ans%mod;

        }
        return t[day]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(t,-1,sizeof(t));
      return  f(1,delay,forget,n);
        

    }
};