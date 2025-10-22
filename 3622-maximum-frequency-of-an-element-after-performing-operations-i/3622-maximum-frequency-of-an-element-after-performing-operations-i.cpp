
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = 200007;  // 2 * 1e5 + 7
        vector<int> freq(n, 0);
        vector<int> pref(n, 0);

        // build frequency array
        for (int i = 0; i < nums.size(); i++) {
            
                freq[nums[i]]++;
        }

        // build prefix sum
        pref[0] = freq[0];
        for (int i = 1; i < n; i++) {
            pref[i] = freq[i] + pref[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int left = max(0, i - k);
            int right = min(n - 1, i + k);

            int noOfElem = pref[right] - (left > 0 ? pref[left - 1] : 0) - freq[i];

           
            int usable = min(noOfElem, numOperations);

            ans = max(ans, usable + freq[i]);
        }

        return ans;
    }
};


