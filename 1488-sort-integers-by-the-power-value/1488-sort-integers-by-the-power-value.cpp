class Solution {
public:
    int getpower(int i){
        int cnt =0;
        while(i!=1){
         if(i%2==0){
            i=i/2;
            cnt++;
         }else{
            i=3*i+1;
            cnt++;
         }
        }
        return cnt;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        for(int i=lo;i<=hi;i++){
         int a=   getpower(i);
            v.push_back({a,i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};