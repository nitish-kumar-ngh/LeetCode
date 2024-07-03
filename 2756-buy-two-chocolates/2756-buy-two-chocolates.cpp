class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        vector <int>debt;
        for (int i=0;i<prices.size();i++){
            if (prices[i]<money)debt.push_back(prices[i]);
        }
        sort(debt.begin(),debt.end());
        int k=-1;
       if (debt.size()>=2) k= money-debt[0]-debt[1];
        if (k>=0)return k;
        else return money;
    }
};