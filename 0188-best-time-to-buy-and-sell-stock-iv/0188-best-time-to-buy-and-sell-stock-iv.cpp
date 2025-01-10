class Solution {
public:
     int t[100003][2][101];
    int f(int i,vector<int>& prices,int b,int k){
       if (i>=prices.size())return 0;
       if (k<=0)return 0;
       int profit=0;
       if (t[i][b][k]!=-1)return t[i][b][k];
       if (b==1){
        profit+=max(-prices[i]+f(i+1,prices,0,k),f(i+1,prices,1,k));
       }else{
        profit+=max(prices[i]+f(i+1,prices,1,k-1),f(i+1,prices,0,k));
       }
       return t[i][b][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
           memset(t,-1,sizeof(t));
        return f(0,prices,1,k);
    }
};