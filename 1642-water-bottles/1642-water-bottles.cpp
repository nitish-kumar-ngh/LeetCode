class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n=numBottles;
        int ans=0;
        while(n>=numExchange){
        int k=n/numExchange;
        ans+=k;
        if (k!=0){
            n=k+n%numExchange;
           
        }else{
            n=k;
        }
        }
        return ans+numBottles;
    }
};