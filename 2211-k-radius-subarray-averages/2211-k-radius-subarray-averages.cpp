class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>result(n,-1);
        if (k==0)return nums;
        if (n<2*k+1)return result;
        int left =0;
        int right = 2*k;
        int i=k;
        long long window=0;
        for (int i=left;i<=right;i++){
            window+=nums[i];
        }
        int count=2*k+1;
        result[i]=window/(count);
        
        right++;
        while(right<n){
            int gya=nums[left];
            int aya=nums[right];
            window=window-gya+aya;
           
            left++;
            right++;
            i++;
             result[i]=window/count;
        }
        return result;

    }
};