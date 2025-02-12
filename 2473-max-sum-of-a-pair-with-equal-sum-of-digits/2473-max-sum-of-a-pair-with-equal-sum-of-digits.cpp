class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>digitsum(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            int s=0;
            int y=nums[i];
              while(y>0){
                  s=s+y%10;
                  y=y/10;
              }
              digitsum[i]=s;
        }
         for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
         for(int i=0;i<nums.size();i++){
            cout<<digitsum[i]<<" ";
        }
        int ans=-1;
        unordered_map<int,int>mp;
        for(int i=nums.size()-1;i>=0;i--){
            if(mp.find(digitsum[i])==mp.end()){
                mp[digitsum[i]]=i;
            }else{
                ans=max(ans,nums[mp[digitsum[i]]]+nums[i]) ;
            }
        }
            
       
        return ans;
    }
};