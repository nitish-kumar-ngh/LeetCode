class Solution {
public:
    
    int countNumbersWithUniqueDigits(int n) {
        vector<int>fact(11,0);
        fact[0]=1;
        for(int i=1;i<11;i++){
            fact[i]=fact[i-1]*i;
        }
        
        int ans =0;
        for(int i=1;i<=n;i++){
            ans=ans+ (fact[10]/fact[10-i]-(fact[9]/fact[9-i+1]));
        }
        return ans+1;
        
    }
};