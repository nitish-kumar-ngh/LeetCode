class Solution {
public:
    int t[101][101][101];
    int f(vector<int>& nums, int k, int op1, int op2, int idx) {
        if (idx >= nums.size()) return 0; // suffix done
        
        if (t[idx][op1][op2] != -1) return t[idx][op1][op2];
        
        int original = nums[idx];
        int ans = original + f(nums, k, op1, op2, idx + 1); // skip ops

        // op1 only
        if (op1 > 0) {
            int after1 = (original + 1) / 2;
            ans = min(ans, after1 + f(nums, k, op1 - 1, op2, idx + 1));
        }

        // op2 only
        if (op2 > 0 && original >= k) {
            int after2 = original - k;
            ans = min(ans, after2 + f(nums, k, op1, op2 - 1, idx + 1));
        }

        // op1 then op2
        if (op1 > 0 && op2 > 0) {
            int after1 = (original + 1) / 2;
            if (after1 >= k) {
                int after12 = after1 - k;
                ans = min(ans, after12 + f(nums, k, op1 - 1, op2 - 1, idx + 1));
            }
            if (original >= k) {
                int after2 = original - k;
                int after21 = (after2 + 1) / 2;
                ans = min(ans, after21 + f(nums, k, op1 - 1, op2 - 1, idx + 1));
            }
        }

        return t[idx][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(t, -1, sizeof(t));
        return f(nums, k, op1, op2, 0);
    }
};
