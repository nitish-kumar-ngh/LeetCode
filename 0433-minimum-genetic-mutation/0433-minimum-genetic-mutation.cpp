class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string b = "ACGT";
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(q.size()>0){
            string a=q.front().first;
            int d = q.front().second;
            if(a==endGene){
                return d;
            }
            q.pop();
            for(int i=0;i<a.size();i++){
                char original = a[i];
                for(int j=0;j<b.size();j++){
                    a[i]=b[j];
                    if(st.find(a)!=st.end()){
                        st.erase(a);
                    q.push({a,d+1});
                    }
                }
                a[i]=original;
            }
        }

       return -1;

    }
};