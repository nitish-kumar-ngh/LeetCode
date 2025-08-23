class Solution {
public:
  long long t[1000001][2];
  int n;
  long  long f(vector<int>& nums,int idx,int prev){
        if(idx>=n)return 0;
        if(t[idx][prev]!=-1)return t[idx][prev];
     long long  profit = INT_MIN;
       if(prev==1){
         profit = max(profit,max(nums[idx]+f(nums,idx+1,0),f(nums,idx+1,1)));
       }else{
             profit = max(profit,max(-nums[idx]+f(nums,idx+1,1),f(nums,idx+1,0)));
       }
       
       // long long  take = val+f(nums,idx+1,!prev);

        return t[idx][prev]= profit;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
         memset(t,-1,sizeof(t));
         return f(nums,0,1);


    }
};