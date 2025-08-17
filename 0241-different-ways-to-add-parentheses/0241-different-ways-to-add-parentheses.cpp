class Solution {
public:
     vector<int> f(string expression) {
         vector<int> result;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='-'||expression[i]=='*'||expression[i]=='+'){
                 vector<int> l=f(expression.substr(0,i));
                  vector<int> r=f(expression.substr(i+1));
                  for(auto left:l){
                    for(auto right:r){
                       if(expression[i]=='-'){
                        result.push_back(left-right);
                       }else if(expression[i]=='+'){
                        result.push_back(left+right);
                       }else if(expression[i]=='*'){
                          result.push_back(left*right);
                       }
                    }
                  }
            }
           
         
        }
           if(result.size()==0){
                int a=stoi(expression);
                return {a};
            
            }
           return result;
     }
    vector<int> diffWaysToCompute(string expression) {
        return f(expression);
    }
};