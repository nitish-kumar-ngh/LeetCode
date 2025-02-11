class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
           
        vector<int>ans;
        vector<int>a;
        int y=0;
       // a.push_back(0);
        for(int i=0;i<arr.size();i++){
           y=y^arr[i];
           a.push_back(y);
        }
        for(auto v:queries){
            int i=v[0];
            int j=v[1];
            // int x=0;
            // for(int k=i;k<=j;k++){
            //    x=x^arr[k];
            // }
            if(i==0)ans.push_back(a[j]);
            else{
                 ans.push_back((a[j])^(a[i-1]));
            }
           
        }
        return ans;
    }
};