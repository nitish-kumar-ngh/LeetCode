class Solution {
public:
    unordered_set<int>kee;
    unordered_set<int>boshai;
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        int n =  status.size();
        vector<int>ans(n,0);
       for (int i = 0; i < initialBoxes.size(); i++) {
    int box = initialBoxes[i];
    if (status[box] == 1) q.push(box);
    else boshai.insert(box);
}

        while(q.size()>0){
            int node = q.front();
            q.pop();
            ans[node]=1;
            //keyhaiyakeinahiisboxme;
            for(auto it:keys[node]){
                kee.insert(it);
            }
            for(auto it:containedBoxes[node]){
               if(status[it]==1){
                q.push(it);
               }else{
                boshai.insert(it);
               }
            }
         vector<int> toErase;
for (auto it : kee) {
    if (boshai.find(it) != boshai.end()) {
        q.push(it);
        boshai.erase(it);
        toErase.push_back(it);
    }
}
for (auto x : toErase) kee.erase(x);


        }
    
        int ans1 =0;
        for(int i=0;i<n;i++){
            if(ans[i]==1){
                ans1=ans1+ candies[i];
            }
        }
        return ans1;
    }
};
