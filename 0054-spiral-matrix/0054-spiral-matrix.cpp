class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        int dir =0;
        while(top<=down && right>=left){
            if(dir==0){
                //left to right (row)->top
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
             if(dir==1){
                //top to down (col)->right
                for(int i=top;i<=down;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }

             if(dir==2){
                //right to left (row)->down
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }

            
             if(dir==3){
                //down to top (col)->left
                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
        }
        return ans;
    }
};