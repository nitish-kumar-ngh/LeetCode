class Solution {
public:
    vector<int>dp;
    int f(vector<int>& days,vector<int>& costs,int idx,int n){
        if (idx>=n)return 0;
        if (dp[idx]!=-1)return dp[idx];
        int cost_1=costs[0]+ f(days,costs,idx+1,n);
        int j=idx;
        int max_days=days[j]+7;
        while(j<n && days[j]<max_days){
            j++;
        }
        int cost_7=costs[1]+ f(days,costs,j,n);
        
         j=idx;
         max_days=days[j]+30;
        while(j<n && days[j]<max_days){
            j++;
        }
        int cost_15=costs[2]+ f(days,costs,j,n);

      return dp[idx]= min(min(cost_1,cost_7),cost_15);

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.clear();
        dp.resize(370,-1);
        int n=days.size();
        return f(days,costs,0,n);
    }
};