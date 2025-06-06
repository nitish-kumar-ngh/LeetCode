class Solution {
public:
int D;
  int dp[11][301];
  int f(vector<int>& jobDifficulty,int day,int idex){
    
    if(day==1){
        int maximum=INT_MIN;
        for(int i= idex;i<jobDifficulty.size();i++){
            maximum=max(maximum,jobDifficulty[i]);
        }
        return dp[day][idex]= maximum;
    }
    if(dp[day][idex]!=-1)return dp[day][idex];
    int maxElemet=INT_MIN;
     int result=INT_MAX;

    for(int i=idex;i<=jobDifficulty.size()-day;i++){
           maxElemet = max(maxElemet,jobDifficulty[i]);
           int answer= maxElemet+f(jobDifficulty,day-1,i+1);
           result =min(result,answer);
    }
    return  dp[day][idex]=result;
  }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        D=d;
        memset(dp,-1,sizeof(dp));
        int n=jobDifficulty.size();
        if (D>n)return -1;
         return f(jobDifficulty,d,0);

    }
};