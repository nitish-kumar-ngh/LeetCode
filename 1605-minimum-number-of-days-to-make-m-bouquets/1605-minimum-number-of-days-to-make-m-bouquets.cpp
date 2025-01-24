class Solution {
public:
    bool f(vector<int>& bloomDay, int m, int k,int ans) {
       int cnt=0,noOfbloom =0;

        for (int i=0;i<bloomDay.size();i++){
           if (bloomDay[i]<=ans){
            cnt++;
           }else{
            noOfbloom+=cnt/k;
            cnt=0;
           }
        }

        noOfbloom+=cnt/k;
        if (noOfbloom>=m)return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn=INT_MAX;
        int mx=INT_MIN;
      //  if(m*k>bloomDay.size())return -1;
        for(int i=0;i<bloomDay.size();i++){
            mn=min(mn,bloomDay[i]);
            mx=max(mx,bloomDay[i]);
        }
       int ans=INT_MAX;
        int low=mn;
        int high=mx;
        while(low<=high){
            int mid=(low+high)/2;
            if (f(bloomDay,m,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

    //     for(int i=mn;i<=mx;i++){
    //         if (f(bloomDay,m,k,i)){
    //             return i;
    //         }
    //     }
    //    return -1;
    if (ans==INT_MAX)return -1;
    else return low;
    }
};