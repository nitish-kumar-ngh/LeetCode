class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if (m>n)return "";
        int reqcount=m;
        int minsize=INT_MAX;
        unordered_map<char,int>mp;
        for (char ch:t){
            mp[ch]++;
        }
         int start_i=0;
        int i=0;
        int j=0;
        while(j<n){
            char x = s[j];
            if (mp[x]>0)reqcount--;
            mp[x]--;
            while (reqcount==0){
                //shrink
                int winsize=j-i+1;
               if(minsize>winsize){
                minsize=winsize;
                start_i=i;
               }
               
                mp[s[i]]++;
                if (mp[s[i]]>0)reqcount++;
                i++;
            }
            j++;
        }
        return minsize==INT_MAX?"":s.substr(start_i,minsize);
    }
};