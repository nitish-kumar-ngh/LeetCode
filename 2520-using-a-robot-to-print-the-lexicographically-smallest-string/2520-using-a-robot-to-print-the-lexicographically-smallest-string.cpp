class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> minIdx(n); 
        minIdx[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
              if (s[i] <= s[minIdx[i + 1]]) {
                    minIdx[i] = i;
                     } else {
                      minIdx[i] = minIdx[i + 1];}    
        }
        string t, paper;
        for (int i = 0; i < n; ++i) {
            t += s[i];
            char minChar;
             if (i + 1 < n) minChar = s[minIdx[i + 1]];
            else minChar = s[minIdx[i]];
                 
            while (!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }
        }
        // ye bhool gya 
        while (!t.empty()) {
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};
