class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      unordered_map<int,int>loss;
      unordered_map<int,int>win;
      for(auto v:matches){
        int x=v[0];
        int y=v[1];
        win[x]++;
        loss[y]--;
      }
     vector<int>ans1;
     vector<int>ans2;
     for(auto a:win) {
        if(loss[a.first]==0){
            if(win[a.first]>0)ans1.push_back(a.first);
        }
     }

    for(auto a:loss) {
        if(loss[a.first]==-1){
           ans2.push_back(a.first);
        }
     }
     vector<vector<int>> find;
     sort(ans1.begin(),ans1.end());
     sort(ans2.begin(),ans2.end());
     find.push_back(ans1);
     find.push_back(ans2);
     return find;

    }
};