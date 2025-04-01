class Solution {
public:
 
 int n;
   long long int t[100005];
  long long  solve(int i,vector<vector<int>>& questions){
        if (i>=n)return 0;
        if (t[i]!=-1)return t[i];
        long long ans=INT_MIN;
        long long pick=questions[i][0]+solve(i+questions[i][1]+1,questions);
        long long Not_pick=solve(i+1,questions);
        ans=max(pick,Not_pick);
        return t[i]= ans;

    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
      memset(t, -1, sizeof(t));

       return  solve(0,questions);
    }
};