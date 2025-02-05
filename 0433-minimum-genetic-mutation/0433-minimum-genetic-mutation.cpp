class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        set<string>s(bank.begin(),bank.end());
        q.push({startGene,0});
        string k="ACGT";
        while(q.size()>0){
            auto v=q.front();
            string ans=v.first;
            int d=v.second;
            if (ans==endGene)return d;
            q.pop();
            for (int i=0;i<ans.size();i++){
                char original=ans[i];
                for (int j=0;j<k.size();j++){
                    ans[i]=k[j];
                    if (s.find(ans)!=s.end()){
                        q.push({ans,d+1});
                        s.erase(ans);
                    }
                }
                ans[i]=original;

            }
        }
        return -1;
    }
};