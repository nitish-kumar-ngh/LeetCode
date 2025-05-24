class Solution {
public:
    int merge(vector<pair<int,int>>&v){
      sort(v.begin(),v.end());
      vector<pair<int,int>>ans;
      for(int i=0;i<v.size();i++){
        if(ans.size()==0 || ans.back().second<=v[i].first){
            ans.push_back(v[i]);
        }else{
            ans.back().second=max(ans.back().second,v[i].second);
        }
      }
     for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second;
     }
      return ans.size();
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>verticle;
        vector<pair<int,int>>horizontal;
        for(int i=0;i<rectangles.size();i++){
            verticle.push_back({rectangles[i][1],rectangles[i][3]});
            horizontal.push_back({rectangles[i][0],rectangles[i][2]});
        }
        int x=merge(verticle);
        cout<<"\n";
       int y=merge(horizontal);
    //   cout<<x<<" "<<y;
        if (x>2 ||y>2)return true;
        else return false;


    }
};