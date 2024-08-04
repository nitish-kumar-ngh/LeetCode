class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
          vector<int>result;
          int n=nums.size();
          int i=0;
          int j=0;
          long long int sum=0;
        long long   int sum1=0;
          
          while(j<n){
          sum+=nums[j];
          if (j-k<0 || j+k>=n){
            result.push_back(-1);
            j++;
          }else{
            sum1=sum;
             for (int m=j+1;m<=j+k;m++){
                sum1=sum1+nums[m];
             }

             
             int b=2*k+1;
             result.push_back(sum1/b);
             sum=sum-nums[i];
             i++;
             j++;
          }
          }
          return result;
    }
};