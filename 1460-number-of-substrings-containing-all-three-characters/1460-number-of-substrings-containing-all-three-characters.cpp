class Solution {
public:
    int numberOfSubstrings(string s) {
        //brute force
        // int cnt=0;
        // for (int i=0;i<s.size();i++){
        //     unordered_set<char>st;
        //     for (int j=i;j<s.size();j++){
        //             st.insert(s[j]);
        //             if (st.size()==3){
        //                 cnt=cnt+(s.size()-j);
        //                 break;
        //                 }
        //     }
        // }
        // return cnt;
       int cnt=0;
       int lastIdx[3]={-1,-1,-1};
       for (int i=0;i<s.size();i++){
            lastIdx[s[i]-'a']=i;
            if (lastIdx[0]!= -1 && lastIdx[0]!= -1 && lastIdx[0]!= -1  ){
                cnt=cnt+(1+min(lastIdx[0],min(lastIdx[1],lastIdx[2])));
            }
       }
       return cnt;

    }
};