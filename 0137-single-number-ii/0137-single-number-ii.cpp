class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>setcnt(32,0);
        vector<int>unsetcnt(32,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){
                    setcnt[j]++;
                }
            }
        }
        int ans =0;
        for(int i=0;i<10;i++){
            cout<<setcnt[i]<<" ";
        }
        cout<<"\n";
       
        for(int i=0;i<32;i++){
            if( setcnt[i]%3!=0)ans=ans+(1<<i);
          
        }
   return ans;
    }
};