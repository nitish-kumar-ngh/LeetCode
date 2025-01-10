class Solution {
public: 
    int t[5001][2];
    int f(int i,vector<int>& prices,int b){
        if(i>=prices.size())return 0;
        if (t[i][b]!=-1)return t[i][b];
        int profit=0;
        if (b==1){
         profit+=  max(-prices[i]+f(i+1,prices,0),f(i+1,prices,1));
        }else{
             profit+=  max(prices[i]+f(i+2,prices,1),f(i+1,prices,0));
        }
        return t[i][b]= profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return f(0,prices,1);
    }
};