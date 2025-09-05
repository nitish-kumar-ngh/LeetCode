class Solution {
public:
    int r;
    int c;
    int t[201][201];
    int f(vector<vector<int>>& dungeon,int i,int j){
        if(i>=r || j>=c)return 1e9;
        if(i==r-1 && j==c-1){
            if( dungeon[i][j]<0){
                return abs( dungeon[i][j])+1;
            }else{
                return 1;
            }
        }
        if(t[i][j]!=-1)return t[i][j];
        int right = f(dungeon,i+1,j);
        int down = f(dungeon,i,j+1);

        int result = min(right,down)- dungeon[i][j];
        return t[i][j]=result >0?result:1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        r=dungeon.size();
        c=dungeon[0].size();
           memset(t,-1,sizeof(t));
      return  f(dungeon,0,0);
    }
};