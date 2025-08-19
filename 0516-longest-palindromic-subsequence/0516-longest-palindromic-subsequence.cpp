class Solution {
public:
    int t1[1001][1001];

    int f(string &s, string &t, int i1, int i2) {
        if(i1 >= s.size() || i2 >= t.size()) return 0;

        if(t1[i1][i2] != -1) return t1[i1][i2];

        if(s[i1] == t[i2]) {
            return t1[i1][i2] = 1 + f(s, t, i1+1, i2+1);
        } else {
            return t1[i1][i2] = max(f(s, t, i1+1, i2),
                                    f(s, t, i1, i2+1));
        }
    }

    int longestPalindromeSubseq(string s) {
        memset(t1, -1, sizeof(t1));
        string t = s;
        reverse(t.begin(), t.end());
        return f(s, t, 0, 0);
    }
};
