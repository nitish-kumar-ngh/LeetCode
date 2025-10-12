class Solution {
public:
    int n;
    int t[13][10004];
    int f(int idx,vector<int>& coins,int amount){
        if(amount == 0) return 0;
        if(idx>=n)return 1e9;
        if(t[idx][amount]!=-1)return t[idx][amount];
        int ans = INT_MAX;
        if(coins[idx]<=amount){
        ans = min({ans,1+f(idx,coins,amount-coins[idx]),f(idx+1,coins,amount)});
        }
        ans = min(ans,f(idx+1,coins,amount));
        return t[idx][amount]= ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        memset(t,-1,sizeof(t));
       return f(0,coins,amount)>=1e9 ?-1:f(0,coins,amount);
    }
};