class Solution {
public:
    int t[52][52];
    int f(vector<int>& values,int i,int j){
        if(i+1==j)return 0;
        if(t[i][j]!=-1)return t[i][j];
        int ans = INT_MAX;
        for(int k =i+1;k<j;k++){
            ans = min(ans,values[i]*values[k]*values[j]+f(values,i,k)+f(values,k,j));
        }
        return t[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(t,-1,sizeof(t));
        int n=values.size();
     return   f(values,0,n-1);
    }
};