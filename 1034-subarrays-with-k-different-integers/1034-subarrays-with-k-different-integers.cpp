class Solution {
public:
 int f(vector<int>& nums, int k){
    int r=0,l=0,cnt=0;
    unordered_map<int,int>mp;
    while(r<nums.size()){
        mp[nums[r]]++;
        while(mp.size()>k){
            mp[nums[l]]--;
            if (mp[nums[l]]==0)mp.erase(nums[l]);
            l=l+1;
        }
        cnt=cnt + (r-l+1);
        r++;
       
    }
     return cnt;
 }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // int cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     unordered_set<int>st;
        //     for(int j=i;j<nums.size();j++){
        //         st.insert(nums[j]);
        //         if (st.size()==k)cnt++;
        //         else if (st.size()>k)break;
        //     }
        // }
        // return cnt;
        int a=f(nums,k);
        int b=f(nums,k-1);
        return abs(a-b);
    }
};