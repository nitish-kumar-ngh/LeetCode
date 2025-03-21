class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> p;
        
        for(int num : nums) {
            p.push(num);
        }

        int cnt = 0;
        while (p.size() > 1 && p.top() < k) { // Ensure at least 2 elements exist
          long long   int x = p.top(); p.pop();
          long long   int y = p.top(); p.pop();
            
            long long m = ((x * 2)  + y) ; // Avoid overflow
            
            p.push(m);
            cnt++;
        }

        return cnt;
    }
};
