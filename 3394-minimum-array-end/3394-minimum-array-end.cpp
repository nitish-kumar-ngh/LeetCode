class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0;
        vector<long long>v;//wo indexpush karo jo unset hai
        for(int i=0;i<64;i++){
            if((x & (1LL << i))==0)v.push_back(i);
        }
        n=n-1;
        for(int i=0;i<64;i++){
            if((n & (1LL << i)))ans+=(1LL << v[i]);
        }
        ans+=x;
        return ans;
    }
};