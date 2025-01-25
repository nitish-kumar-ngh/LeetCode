class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0;
        int right=0;
        unordered_map<int,int>mp;
        int ans=0;
       // if (fruits.size()==1)return 1;
        while(right<fruits.size()){
            mp[fruits[right]]++;
            if (mp.size()<2){
                ans=max(ans,right-low+1);
                right++;
            }else if (mp.size()==2){
                ans=max(ans,right-low+1);
                right++;
            }else{
                while(mp.size()>2){
                    mp[fruits[low]]--;
                    if (mp[fruits[low]]==0)mp.erase(fruits[low]);
                    low++;
                }
                right++;
            }
        }
        return ans;
    }
};