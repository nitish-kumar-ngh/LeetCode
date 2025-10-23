class Solution {
public:
    int r,c;
    vector<string>result;
    unordered_set<string>sts;
    class TriNode{
    public:
    string word;
    bool endOfWord;
    TriNode*character[26];
    };
    TriNode *getnode(){
        TriNode *root = new  TriNode();
         root->word="";
         root->endOfWord = false;
         for(int i=0;i<26;i++){
            root->character[i]=NULL;
         }
         return root;
    }
    void insert(TriNode *root,string &w){
        TriNode *temp = root;
        for(int i=0;i<w.size();i++){
            char ch = w[i];
            if(temp->character[ch-'a']==NULL){
                temp->character[ch-'a']=getnode();
            }
            temp=temp->character[ch-'a'];
        }
        temp->word =w;
        temp->endOfWord=true;
    }
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};
    void find (TriNode*root,int i,int j,vector<vector<char>>& board){
        if(i<0 ||j<0 ||i>=r||j>=c||board[i][j]=='&')return;
        if(root->character[board[i][j]-'a']==NULL)return;

        root = root->character[board[i][j]-'a'];
        if(root->endOfWord==true){
            sts.insert(root->word);
        }
        for(int d =0;d<4;d++){
            int nx = i+dx[d];
            int ny = j+dy[d];
            char t =  board[i][j];
            board[i][j]= '&';
            find (root,nx,ny,board);
            board[i][j]= t;
        }

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         TriNode*root = getnode();
         for(int i=0;i<words.size();i++){
            insert(root,words[i]);
         }
         r = board.size();
         c = board[0].size();

         for(int i=0;i<r;i++){
           for(int j =0;j<c;j++){
              if(root->character[board[i][j]-'a']!=NULL) find(root,i,j,board);
             
           }
         }
       
         for(auto it:sts){
            result.push_back(it);
         }
         return result;
    }
};