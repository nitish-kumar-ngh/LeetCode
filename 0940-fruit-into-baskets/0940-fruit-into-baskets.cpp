class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int mxlen=0;
        unordered_map<int,int>mp;
        while(r<fruits.size()){
          mp[fruits[r]]++;
          while(mp.size()>2){
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0)mp.erase(fruits[l]);
            l++;
          }
          mxlen=max(mxlen,r-l+1);
          r++;
        }
        return mxlen;
    }
};