class Solution {
public:
    class TrieNode{
        public:
       TrieNode*character[10];
    };

    TrieNode* getnode(){
          TrieNode*temp = new TrieNode();
          for(int i =0;i<10;i++){
            temp->character[i]=NULL;
          }
          return temp;
    }
    void insert(int num,TrieNode*root){
        TrieNode* temp = root;
        string numstr = to_string(num);
        for(int  i =0;i<numstr.size();i++){
            int idx = numstr[i]-'0';
            if(temp->character[idx]==NULL){
                temp->character[idx] = getnode();
            }
            temp =  temp->character[idx] ;
        }
        
    }
    int  search(int num, TrieNode* root){
        string str = to_string(num);
        TrieNode* temp = root;
        int len =0;
        for(int i =0;i<str.size();i++){
            int idx = str[i]-'0';
            if(temp->character[idx]!=NULL){
                len++;
                temp=temp->character[idx];
            }else{
                break;
            }
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getnode();
        for(int i =0;i<arr1.size();i++){
            insert(arr1[i],root);
        }
        int result =0;
        for(int i =0;i<arr2.size();i++){
            result = max(result , search(arr2[i],root));
        }
        return result;
    }
};