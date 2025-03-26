class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>v(1000005,1);
        v[0]=0;
        v[1]=0;
        for (int i=2;i*i<1000005;i++){
            if (v[i]==1){
               for (int j=i;i*j<1000005;j++){
                     v[i*j]=0;
               }
            }
        }
       
        vector<int>ans;
        for (int j=left;j<=right;j++){
            if (v[j]==1)ans.push_back(j);
        }
        
        if (ans.size()<2) return {-1,-1};
         for (int j=left;j<=right;j++){
             if (v[j]==1)cout<<j<<" ";
        }
        vector<pair<int,pair<int,int>>>answer;
         for (int i=0;i<ans.size()-1;i++){
            answer.push_back({ans[i+1]-ans[i],{ans[i],ans[i+1]}});
         }
       sort(answer.begin(),answer.end());
        vector<int>m;
        for (auto x:answer){
            m.push_back(x.second.first);
            m.push_back(x.second.second);
            break;
        }
      return m;
    }
};