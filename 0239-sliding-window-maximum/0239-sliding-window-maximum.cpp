class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>s;
        for(int i=0;i<k-1;i++){
            s.insert(nums[i]);
        }
        vector<int>ans;
        int j =0;
        for(int i=k-1;i<n;i++){
            s.insert(nums[i]);
           auto it = *s.rbegin();
           ans.push_back(it);
           auto it1 = s.find(nums[j]);          
          if (it1 != s.end()) s.erase(it1); 
           j++;

        }
        return ans;
    }
};