
   class Solution {
public:
    vector<vector<int>> result;
    
    void f(int idx, vector<int>& candidates, int target, vector<int>& temp, int s) {
        if (s == target) {
            result.push_back(temp);
            return;
        }
        if (s > target || idx >= candidates.size()) return;

        // Explore each candidate and make sure to skip duplicates
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
            
            temp.push_back(candidates[i]);
            f(i + 1, candidates, target, temp, s + candidates[i]); // Move to next index
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        vector<int> temp;
        f(0, candidates, target, temp, 0);
        return result;
    }
};

