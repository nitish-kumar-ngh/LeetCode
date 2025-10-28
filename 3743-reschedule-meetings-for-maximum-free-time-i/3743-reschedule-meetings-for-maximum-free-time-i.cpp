class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int,int>>p;
        int n = startTime.size();
        for(int i =0;i<n;i++){
            p.push_back({startTime[i], endTime[i]});
        }
        sort(p.begin(),p.end());
        vector<int>free;
        int f =0;
        for(int i =0;i<p.size();i++){
            int s=p[i].first;
            int e = p[i].second;
            free.push_back(abs(f-s));
            f =e;;
        }
        free.push_back(abs(eventTime-f));
        int ans =0;
        int  l =0;
        int r = 0;
        int sum =0;
        while(r<free.size()){
     sum+=free[r];
     while(r-l+1>k+1){
       
        sum-=free[l];
         l++;
     }
     ans=max(sum,ans);
     r++;
        }
   return ans;
    }
};