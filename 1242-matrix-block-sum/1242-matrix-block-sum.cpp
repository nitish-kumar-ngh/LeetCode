class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int x = mat.size();
        int y = mat[0].size();
        vector<vector<int>> answer(x,vector<int>(y,0));
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                int ans=0;
                int nlow_x=i-k;
                int nhigh_x=i+k;
                if(nhigh_x>=x)nhigh_x=x-1;
                if(nlow_x<0)nlow_x=0;
                 int nlow_y=j-k;
                int nhigh_y=j+k;
                if(nhigh_y>=y)nhigh_y=y-1;
                if(nlow_y<0)nlow_y=0;
                for(int k=nlow_x;k<=nhigh_x;k++){
                    for(int m=nlow_y;m<=nhigh_y;m++){
                     ans+=mat[k][m];
                    }
                }
                answer[i][j]=ans;
            }
        }
        return answer;
    }
};