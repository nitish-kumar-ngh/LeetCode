#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // We only need to consider the fruits within a reasonable range.
        // The farthest we can go is startPos + k or startPos - k.
        // We can use a sliding window over the fruits array.

        int n = fruits.size();
        vector<int> positions;
        vector<int> amounts;
        for(const auto& fruit : fruits) {
            positions.push_back(fruit[0]);
            amounts.push_back(fruit[1]);
        }
        
        // Create a prefix sum array for the amounts
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + amounts[i];
        }

        int maxFruits = 0;
        int left = 0;

        // The right pointer of the sliding window
        for (int right = 0; right < n; ++right) {
            int pos_r = positions[right];
            
            // Shrink the window from the left until it's reachable within k steps
            while (left <= right) {
                int pos_l = positions[left];
                
                // Calculate steps for the current window [pos_l, pos_r]
                // Case 1: The entire window is to the right of startPos (or includes it)
                // Path: startPos -> pos_l -> pos_r
                int steps1 = (pos_r - startPos) + (pos_r - pos_l);
                
                // Case 2: The entire window is to the left of startPos (or includes it)
                // Path: startPos -> pos_r -> pos_l
                int steps2 = (startPos - pos_l) + (pos_r - pos_l);

                // If startPos is outside the window, one of these is negative/wrong.
                // A simpler, always-correct formula is:
                // (distance to travel the whole window) + (distance from start to nearest end)
                int steps = (pos_r - pos_l) + min(abs(startPos - pos_l), abs(startPos - pos_r));

                if (steps > k) {
                    // This window is too big/far, shrink it from the left
                    left++;
                } else {
                    // This window is valid, so we don't need to shrink further for this 'right'
                    break; 
                }
            }

            // After shrinking, the window [left, right] is the largest possible valid window
            // ending at `right`. Calculate its fruit sum.
            if (left <= right) {
                long long currentFruits = prefixSum[right + 1] - prefixSum[left];
                maxFruits = max(maxFruits, (int)currentFruits);
            }
        }

        return maxFruits;
    }
};