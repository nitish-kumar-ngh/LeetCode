class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n=instructions.size();
        int i=0;
        vector<int>vis(n,0);
        long long s=0;
        while(i>=0&&i<n &&vis[i]==0){
            if (instructions[i]=="add"){
                s+=values[i];
               
                vis[i]=1;
                 i++;
            }else {
                vis[i]=1;
                i=i+values[i];

            }
        }
        return s;
    }
};