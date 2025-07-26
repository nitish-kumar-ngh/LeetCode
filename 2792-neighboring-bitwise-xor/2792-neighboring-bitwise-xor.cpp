class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>originalwith0;
        originalwith0.push_back(0);
          vector<int>originalwith1;
          originalwith1.push_back(1);
          for(int i=0;i<derived.size()-1;i++){
            if(derived[i]==0){
                originalwith0.push_back(originalwith0.back());
                originalwith1.push_back(originalwith1.back());
            }else{
                originalwith0.push_back(!originalwith0.back());
                 originalwith1.push_back(!originalwith1.back());
            }
          }
         
          if(derived[derived.size()-1]== originalwith0[derived.size()-1]^ originalwith0[0] ||  derived[derived.size()-1]== originalwith1[derived.size()-1]^ originalwith1[0])return true;
         
          return false;
    }
};