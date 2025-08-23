class Solution {
public:
  long long t[1000001][2];
  int n;
  long  long f(vector<int>& nums,int idx,int prev){
        if(idx>=n)return 0;
        if(t[idx][prev]!=-1)return t[idx][prev];
       long long  skip = f(nums,idx+1,prev);
      long long  val =nums[idx];
        if(prev == 0){
             val=-nums[idx];
        }
        long long  take = val+f(nums,idx+1,!prev);

        return t[idx][prev]= max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
         memset(t,-1,sizeof(t));
         return f(nums,0,1);


    }
};