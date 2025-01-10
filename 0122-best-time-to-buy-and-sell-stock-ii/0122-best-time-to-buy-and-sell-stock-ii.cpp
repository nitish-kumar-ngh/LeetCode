class Solution {
public:
   // int t[30003][30003];
    // int f (int i,vector<int>& prices,int a){
    //     if (i>=prices.size())return 0;
    //     int profit=0;
    //     if(t[i][a]!=-1)return t[i][a];
    //    if(a==1){
    //     profit=profit+max(-prices[i]+f(i+1,prices,0),f(i+1,prices,1));
    //    }else{
    //      profit=profit+max(prices[i]+f(i+1,prices,1),f(i+1,prices,0));
    //    }
    //    return t[i][a]= profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int t[n+1][2];
       memset(t,0,sizeof(t));
       //return f(0,prices,1);
       for(int i=prices.size()-1;i>=0;i--){
        for(int a=1;a>=0;a--){
         int profit=0;
       
       if(a==1){
        profit=profit+max(-prices[i]+t[i+1][0],t[i+1][1]);
       }else{
         profit=profit+max(prices[i]+t[i+1][1],t[i+1][0]);
       }
       t[i][a]= profit;
       //return t[i][a]= profit;
       }
       }
       return t[0][1];
    }
};