class Solution {
public:
int ans=INT_MAX;
int t[13][10004];
    int f(vector<int>& coins,int i,int amt){
        if (amt==0)return 0;
        if (amt<0)return 1e8;
        if (i>=coins.size())return 1e8;
        if (t[i][amt]!=-1)return t[i][amt];
        int ans=1e8;
        if(coins[i]<=amt){
           ans=min(ans,1+f(coins,i,amt-coins[i]));
               ans=min(ans,1+f(coins,i+1,amt-coins[i]));
             ans=min(ans,f(coins,i+1,amt));
        }else{
             ans=min(ans,f(coins,i+1,amt));
        }
        return t[i][amt]= ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
       return f(coins,0,amount)==1e8?-1:f(coins,0,amount);
       // return ans==INT_MAX?-1:ans;
    }
};