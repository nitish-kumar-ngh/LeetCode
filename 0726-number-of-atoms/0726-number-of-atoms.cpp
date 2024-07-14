class Solution {
public:
    string countOfAtoms(string formula) {
    int n=formula.size();
       stack<unordered_map<string,int> >st;
       st.push(unordered_map<string,int>());
       int i=0;
       while (i<n){
       if (formula[i]=='('){
        st.push(unordered_map<string,int>());
        i++;
       }else if (formula[i]==')'){
        unordered_map<string,int> curr=st.top();//map at top
        st.pop();
        i++;
        string mult;
        while(i<n && isdigit(formula[i])){
            mult.push_back(formula[i]);
            i++;
        }
        if (!mult.empty()){
            int currmult=stoi(mult);
            for(auto it:curr){
                string a=it.first;
                int freq=it.second;
                curr[a]=freq*currmult;
            }
        }
        //merge top element with curr
       for (auto it:curr){
        string element=it.first;
        int count=it.second;
        st.top()[element]+=count;
       }
  
       }else{
        string abhijoelement;
        abhijoelement.push_back(formula[i]);//me2
        i++;
        while(i<n && isalpha(formula[i])&& islower(formula[i])){
            abhijoelement.push_back(formula[i]);
            i++;
        }
        string currcount;
        while(i<n && isdigit(formula[i])){
            currcount.push_back(formula[i]);
            i++;
        }
        int currco=(currcount.empty())?1:stoi(currcount);
        st.top()[abhijoelement]+=currco;
        

       }

       }
      map<string,int>mp(st.top().begin(),st.top().end());
      string result="";
      for (auto it:mp){
        string ele=it.first;
        int cnt=it.second;
        result+=ele;
        if (cnt>1)result+=to_string(cnt);
      }
       return result;
    }
};