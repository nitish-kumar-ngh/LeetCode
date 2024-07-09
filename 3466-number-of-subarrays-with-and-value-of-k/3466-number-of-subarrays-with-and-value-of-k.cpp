class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        map<long long int,long long int>prev_ele;
        map<long long int,long long int>all_subArrays;
        int n=nums.size();
        for (long long int i=n-1;i>=0;i--){
         map<long long int ,long long int>new_ele;
         for (auto v:prev_ele){
          new_ele[v.first&nums[i]]=max(new_ele[v.first&nums[i]],v.second);
         }
         new_ele[nums[i]]=max(new_ele[nums[i]],i);
         prev_ele = new_ele;
         vector<pair<int,int>>ranges(new_ele.begin(),new_ele.end());
         reverse(ranges.begin(),ranges.end());
         for (int en=0;en<ranges.size();en++){
            if (en==0){
            all_subArrays[ranges[en].first]+=ranges[en].second -i+1;
            }else{
                all_subArrays[ranges[en].first]+=(ranges[en].second - ranges[en-1].second);
            }

             
         }
        }
        return all_subArrays[k];
    }
};