class Solution {
public:
    bool p(string k){ string t = k; reverse(k.begin(),k.end()); return t==k; }


    int maxProduct(string s) {
        int n=s.size();
        int t =1<<n;
        vector<int>palin(t,0);
        for(int mask = 1;mask<t;mask++){
            string sub ="";
            for(int i = 0;i<n;i++){
                 if (mask & (1<<i))sub+=s[i];
            }
            if(p(sub))palin[mask]=sub.size();
        }
         int ans = 0;
        for (int mask1 = 1; mask1 < t; mask1++) {
            for (int mask2 = mask1+1; mask2 < t; mask2++) {
                if ((mask1 & mask2) == 0) { 
                    ans = max(ans, palin[mask1] * palin[mask2]);
                }
            }
        }
        return ans;
    }
};