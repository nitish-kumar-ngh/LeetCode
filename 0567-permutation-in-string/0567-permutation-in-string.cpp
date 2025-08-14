class Solution {
public:
    bool checkInclusion(string t, string s) {
        int l=0;
        int r=0;
        int mxlen=INT_MAX;
        int st=0;
        vector<int>hash(256,0);
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int cnt =0;
        while(r<s.size()){
             if(hash[s[r]]>0)cnt++;
             hash[s[r]]--;
             while(cnt==t.size()){
                if(mxlen>r-l+1){
                    mxlen=r-l+1;
                    st=l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;

             }
             r++;
        }
        if(mxlen==INT_MAX)mxlen=0;
        if(mxlen==t.size())return true;
        else return false;
    }
};