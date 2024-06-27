class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());

        unordered_set<string>visited;

        queue<string>que;

        que.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!que.empty()){
               int N=que.size();
               while(N--){
                string curr=que.front();
                if (curr==endGene)return level;
                que.pop();
                for (char ch:"ACGT"){
                    for (int i=0;i<curr.size();i++){
                        string neighbour=curr;
                        neighbour[i]=ch;//firstly A THen C,G,T
                        if(bankset.find(neighbour)!=bankset.end()&& visited.find(neighbour)==visited.end()){
                            que.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
               }
               level++;



        }
        return -1;
    }
};