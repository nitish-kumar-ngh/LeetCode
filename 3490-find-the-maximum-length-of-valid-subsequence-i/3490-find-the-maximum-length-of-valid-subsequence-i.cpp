class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int codd=0;
        int ceven=0;
        int ceo=0;
        int coe=0;
        int prev=0;
       // int prev2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                if(ceo==0)ceo++;
               ceven++;
               if( prev==1){//odd
                coe++;
                ceo++;

               }
               prev=2;
            }else{
                 codd++;
                 if(coe==0)coe++;
                 if(prev==2){//even
                   ceo++;
                   coe++;
                 }
                 prev=1;
            }
        }
        return max({codd,ceven,ceo,coe});
    }
};