class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>prefix(n+1,0);
        vector<long long int>suffix(n+1,0);
        for (int i=0;i<nums.size();i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
           for (int i=nums.size()-1;i>=0;i--){
           suffix[i]=nums[i]+suffix[i+1];
        }
      long long   int cnt=0;
        for (int i=1;i<n;i++){
            if (prefix[i]>=suffix[i])cnt++;
        }
        return cnt;
    }
};