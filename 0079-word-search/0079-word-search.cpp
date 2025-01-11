// class Solution {
// public:
//     int t[7][7][17];
//     int m,n;
//     vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
//     bool isavailble(int i,int j,int idx,string &word,vector<vector<char>>& board){
//          if(idx>=word.size())return true;
//          if(i<0||i>=m||j<0||j>=n||board[i][j]!=word[idx])return false;
//          //backtracking 
//        //  if(t[i][j][idx]!=-1)return t[i][j][idx];
//          char temp=word[idx];
//          board[i][j]='*';
//          for (auto d:dir){
//             int i_=i+d[0];
//             int j_=j+d[1];
//             if (isavailble(i_,j_,idx+1,word,board)){
//                  //board[i][j] = temp;
//              return true;
//             } 
//          }
//           board[i][j]=temp;
         
//     return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         memset(t,-1,sizeof(t));
//         m=board.size();
//         n=board[0].size();
//         int l=word.size();
//            if(m*n < l)
//             return false;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]==word[0]){//charter first is matched
//                 if(isavailble(i,j,0,word,board)){
//                     return true;
//                 }
//                 }
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    int  m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if(idx >= word.size())
            return true;
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        // l = word.length();
        // if(m*n < l)
        //     return false;
        
      m=board.size();
        n=board[0].size();
        int l=word.size();
           if(m*n < l)
            return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){//charter first is matched
                if(find(board,i,j,word,0)){
                    return true;
                }
                }
            }
        }
        return false;
    }
};