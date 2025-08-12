class Solution {
public:
int mod = 1000000007;
   int t[305][1000];
  int f(vector<int>&v,int target,int idx){
    if(target ==0)return t[target][idx]=1;
    if(idx==0){
        if(v[idx]==target)return t[target][idx]= 1;
        else return t[target][idx]=0;
    }
    if(t[target][idx]!=-1)return t[target][idx];
    int ans=0;
    ans=(ans %mod+ f(v,target,idx-1)%mod)%mod;
    if(v[idx]<=target){
        ans=(ans%mod+f(v,target-v[idx],idx-1)%mod)%mod;
    }
    return t[target][idx]=ans;
  }
    int numberOfWays(int n, int x) {
        memset(t,-1,sizeof(t));
        vector<int>v;
         int num=1;
         while(num<=n && pow(num,x)<=n){
          v.push_back(pow(num,x));
          num++;
         }
         for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
         }
         //return 1;
        if(v.size()>0)return f(v,n,v.size()-1);
        return 1;
    }
};