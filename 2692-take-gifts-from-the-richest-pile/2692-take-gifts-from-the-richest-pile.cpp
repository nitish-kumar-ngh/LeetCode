class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for(int i=0;i<k;i++){
            sort(gifts.begin(),gifts.end());
            gifts[gifts.size()-1]=floor(sqrt( gifts[gifts.size()-1]));
        }
        long long ans=0;
        for (int i=0;i<gifts.size();i++){
            ans+=gifts[i];
        }
        return ans;
    }
};