class Solution {
public:
void dfs(int index,vector<vector<int>>& stones,vector<bool>&visited){
     visited[index]=true;

     for (int i=0;i<stones.size();i++){
        int r=stones[index][0];
        int c=stones[index][1];
        if ((!visited[i]) && (stones[i][0]==r||stones[i][1]==c)){
            dfs(i,stones,visited);
        }
     }


}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int grp=0;
        vector<bool>visited(n,false);
        for (int i=0;i<n;i++){
            // if (!visited[i]){
            //     dfs(i,stones,visited);
            //     grp++;
            // }
            if (visited[i]==true)continue;
            dfs(i,stones,visited);
            grp++;
        }
        return n-grp;
    }
};