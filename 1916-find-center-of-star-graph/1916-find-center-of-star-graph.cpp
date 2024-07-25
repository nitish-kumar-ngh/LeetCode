class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>v(100005,0);
        for (auto edge:edges){
            v[edge[0]]++;
            v[edge[1]]++;
        }
        int maxi=INT_MIN;
        for (int i=1;i<100005;i++){
            maxi=max(maxi,v[i]);
        }
        for (int i=1;i<100005;i++){
           if (maxi==v[i])return i;
        }
       return -1;
    }
};