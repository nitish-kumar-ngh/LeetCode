class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2,int k) {
        vector<pair<long long int,long long int>>v;
        for(long long int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
        multiset<long long int>s1;
        multiset<long long int>s2;
        // vector<pair<long long int,long long int>>v2;
        // for(long long int i=0;i<nums1.size();i++){
        //     v.push_back({nums1[i],nums2[i]});
        // }
        //  sort(v2.begin(),v2.end());
        sort(nums1.begin(),nums1.end());
         long long int i=nums1.size()-1;
         long long int calsum=0;
         long long int k1=k;
         while(k1-1>0){
            s2.insert(nums1[i]);
             calsum+=nums1[i];
            i--;
            k1--;
         }
         for(auto it:s2){
            cout<<it<<" ";
         }
        // for(long long int i=0;i<nums1.size()-k-1;i++){
        //   s1.insert(nums1[i]);
        // }
        long long int n=nums1.size();
         long long int noofelem=n-(k-1);
         long long int j=0;
         while(noofelem>0){
              s1.insert(nums1[j]);
              j++;
              noofelem--;
         }
         for(auto it:s1){
            cout<<it<<" ";
         }
         long long int mxans=0;
         for(long long int i=0;i<v.size();i++ ){
            long long int a=v[i].first;
            long long int b=v[i].second;
            if (s2.find(b)!=s2.end()){
              if (s1.size()>0){
                mxans=max(mxans,(calsum+*s1.rbegin())*a);
                auto it=s2.find(b);
               s2.erase(it);
               s2.insert(*s1.rbegin());
                calsum=calsum-b+*s1.rbegin();
                auto it2=s1.find(*s1.rbegin());
               s1.erase(it2);
              } 
            }else{
                   mxans=max(mxans,(calsum+b)*a);
                  if (s1.size()>0){
                    auto it=s1.find(b);
                    s1.erase(it);
                  } 
            }
         }
          return mxans;
    }
};