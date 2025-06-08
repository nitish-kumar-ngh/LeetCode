class Solution {
public:
    int dp[50004];
   vector<pair<pair<int, int>, int>> p;
    int pred(int i,int last){
        if(p[i].first.first>=last)return 1;
        else return 0;
    }
     int getindex(int value){
        int l=0;
        int r=p.size();
        while(l+1<r){
            int mid=l+(r-l)/2;
            if(pred(mid,value)==0)l=mid;
            else r=mid;
        }
        return r;
     }
    int f( int idx) {
        if (idx>=p.size())return dp[idx] =0;
        //taken
        if (dp[idx]!=-1)return dp[idx];
        int ans=INT_MIN;

      ans=max(ans,p[idx].second+f(getindex(p[idx].first.second)));
      //nottake
      ans=max(ans,f(idx+1))  ;
    return dp[idx]=ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      //  vector<pair<pair<int, int>, int>> p;
         p.clear(); 
        for (int i = 0; i < startTime.size(); i++) {
            p.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        memset(dp,-1,sizeof(dp));
        sort(p.begin(), p.end());

        return f(0);
    }
};
