class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int mid) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Apply first `mid` queries as range updates
        for (int i = 0; i < mid; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) diff[r + 1] += val;
        }

        // Build prefix sum
        for (int i = 1; i < n; i++) diff[i] += diff[i - 1];

        // Check if all elements become <= 0
        for (int i = 0; i < n; i++) {
            if (nums[i] + diff[i] > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt++;
        }
        if(cnt==n)return 0;

        int l = 1, r = queries.size(), ans = -1;

        // Binary search over number of queries
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(nums, queries, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
