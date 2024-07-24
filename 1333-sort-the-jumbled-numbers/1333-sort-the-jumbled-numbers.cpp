class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int>m;
        vector<pair<int,int> >v;
        auto alpha=[&](pair<int,int>a,pair<int,int>b){
              return a.second<b.second;
            //    if (a.second==b.second){
            //     //return a.first<b.first;
            //    }else return a.second<b.second;
        };
        for (int i=0;i<nums.size();i++){
            int x=nums[i];
            string s= to_string(x);
            string result="";
            for (int i=0;i<s.size();i++){
                int z=s[i]-'0';
                int k=mapping[z];
                result+=to_string(k);
              
            }
            // cout<<result<<" ";
              int b=stoi(result);
             
              v.push_back(make_pair(x,b));
              cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
        
        sort(v.begin(),v.end(),alpha);
        vector<int>ans;
        for (auto ele:v){
            ans.push_back(ele.first);
        }
        return ans;
    }
};