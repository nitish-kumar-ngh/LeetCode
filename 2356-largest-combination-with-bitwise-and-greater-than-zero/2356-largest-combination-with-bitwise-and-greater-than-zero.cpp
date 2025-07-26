class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>v(32,0);
       
            for(int i=0;i<candidates.size();i++){
             for(int j=0;j<32;j++){    
              if(candidates[i]& 1<<j)v[j]++;
             }
        }
        int ans =0;
        for(int i=0;i<32;i++){
            ans=max(ans,v[i]);
        }
       return ans; 
       
    }
};