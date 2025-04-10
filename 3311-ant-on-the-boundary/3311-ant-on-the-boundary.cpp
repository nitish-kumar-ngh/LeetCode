class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n=nums.size();
        vector<int>psum(n,0);
        psum[0]=nums[0];
        int cnt=0;
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+nums[i];

        }
           for(int i=0;i<n;i++){
           if (psum[i]==0)cnt++;
            
        }
        return cnt;

    }
};