class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        int n=bills.size();
         for (int i=0;i<n;i++){
            if (bills[i]==5){
                cnt5++;
            }else if (bills[i]==10){
                if (cnt5>0){
                    cnt5--;
                }else return false;
                cnt10++;
            }else if (bills[i]==20){
                if (cnt5>0 && cnt10>0){
                    cnt5--;
                    cnt10--;
                }else if (cnt5>2){
                     cnt5=cnt5-3;
                }else return false;

            }
         }
         return true;
    }
};