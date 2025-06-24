class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        int i = happiness.size()-1;
        long long ans =0;
        int cnt =0;
        while(i>=happiness.size()-k && cnt<k){
            if(happiness[i]-cnt>=0)ans+=happiness[i]-cnt;
            cnt++;
            i--;
        }
         
        return ans;
    }
};