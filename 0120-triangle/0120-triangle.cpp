class Solution {
public:
int m,n;
    int t[205][205];
   int f(int i,int j,vector<vector<int>>& triangle){
    if(i>=triangle.size()|| j>=triangle[i].size())return 1e9;
    if (i==triangle.size()-1 && j<triangle[i].size())return triangle[i][j];
    if(t[i][j]!=-1)return t[i][j];
    return t[i][j]= triangle[i][j]+min(f(i+1,j,triangle),f(i+1,j+1,triangle));
   }
    int minimumTotal(vector<vector<int>>& triangle) {
       memset(t,-1,sizeof(t));
      return f(0,0,triangle);   
    }
};