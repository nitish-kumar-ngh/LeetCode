class Solution {
public:
    bool f(vector<int>& nums, int threshold,int mid){
        int ans=0;
        for (int i=0;i<nums.size();i++){
            ans+=ceil((float)nums[i]/mid);
        }
        cout<<ans<<" ";
        if (ceil(ans)<=threshold)return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high=1e7;
        while(low<=high){
            int mid=(low+high)/2;
            if (f(nums,threshold,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};