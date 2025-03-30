class Solution {
public:
 static bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; 
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          vector<vector<int>>v;
        for(int i=0;i<intervals.size();i++){
            v.push_back(intervals[i]);
        }
        sort(v.begin(),v.end(),cmp);
        int freetime=v[0][1];
        int cnt=1;
        for(int i=0;i<intervals.size();i++){
            if (v[i][0]>=freetime){
                cnt++;
                freetime=v[i][1];
            }
        }
        return v.size()-cnt;
    }
};