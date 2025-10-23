class Trie {
public:
    
    class TreeNode {
      public:
      string w;
      bool end;
      TreeNode* character[26];

    };
    
    TreeNode* getnode(){
        TreeNode* root = new TreeNode();
        root->w = "";
        root->end = false;
        for(int  i =0;i< 26 ;i++){
            root->character[i] = NULL;
        }
        return root  ;
      
    }
     TreeNode* root;
    Trie() {
      root = getnode();
    }
    
    void insert(string word) {
      TreeNode* temp = root ;
      for(int  i=0;i<word.size();i++){
        char ch = word[i];
        if(temp->character[ch-'a']==NULL){
            temp->character[ch-'a']=getnode();
           
        }
         temp = temp->character[ch-'a'];
      }
      temp->end = true;
      temp->w = word;
   
    }
    
    bool search(string word) {
      TreeNode * temp = root;
      for(int i =0;i<word.size();i++){
        if(temp->character[word[i]-'a']==NULL)return false;
        temp=temp->character[word[i]-'a'];
      }
      if(temp->end == true)return true;
      else return false;


    }
    
    bool startsWith(string prefix) {
     int cnt =0;
     TreeNode*temp = root;
     for(int i=0;i<prefix.size();i++){
         if(temp->character[prefix[i]-'a']==NULL)return false;
         temp=temp->character[prefix[i]-'a'];
        
     }

     return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */