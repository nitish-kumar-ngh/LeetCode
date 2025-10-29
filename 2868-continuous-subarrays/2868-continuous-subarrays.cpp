class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
    multiset<int>s;
    int  l=0;
    int r =0;
   long long  int ans =0;
    while(r<nums.size()){
        s.insert(nums[r]);
        while(abs(*s.rbegin()-*s.begin())>2){
            auto it = s.find(nums[l]);
            s.erase(it);
            l++;
        }
        ans+=(r-l+1);
        r++;
    }
    return ans;
    }
};