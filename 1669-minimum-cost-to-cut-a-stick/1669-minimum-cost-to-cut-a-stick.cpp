class Solution {
public:
    int t[101][101];
    int f (int i,int j,vector<int>& cuts){
        if (i>j)return 0;
        if(t[i][j]!=-1)return t[i][j];
        int mini=INT_MAX;
        for (int ind=i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts)+f(ind+1,j,cuts);
            mini=min(mini,cost);
            t[i][j]=mini;
        }
        return t[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(t,-1,sizeof(t));
        int c=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return f(1,c,cuts);
    }
};