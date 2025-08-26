class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
         vector<pair<int,int>>v;
        for(int i=0;i<dimensions.size();i++){
            int x = dimensions[i][0];
            int y = dimensions[i][1];
            int z = x*x+y*y;
            //mp[z]=x*y;
            v.push_back({z,x*y});

        }
       sort(v.begin(),v.end());
       int ans =0;
       int mx = v.back().first;
       for(int i=v.size()-1;i>=0;i--){
        if(v[i].first ==mx){
            ans=max(ans,v[i].second);
        }
       }
       return ans;
    }
};