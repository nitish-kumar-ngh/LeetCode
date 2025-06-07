class Solution {
public:
   struct cmp {
    bool operator()(pair<char, int> a, pair<char, int> b) {
        if (a.first != b.first)
            return a.first > b.first;    
        return a.second < b.second;       
    }
};
    typedef pair<char,int>p;
    typedef pair<int ,char>p1;
    string clearStars(string s) {
        priority_queue<p,vector<p>,cmp>pq;
        for(int i=0;i<s.size();i++){
            if (s[i]=='*'){
            if(pq.size()>0){
                pq.pop();
            }

            }
           if (s[i]!='*') pq.push({s[i],i});
        }

        priority_queue<p1,vector<p1>,greater<p1>>pq2;
        while(pq.size()>0){
            char ch =pq.top().first;
            int idx=pq.top().second;
            pq2.push({idx,ch});
            pq.pop();
        }
        string ans;
         while(pq2.size()>0){
            char ch =pq2.top().second;
           // int idx=pq.top().second;
           // pq2.push({idx,ch});
           ans+=ch;
            pq2.pop();
        }
        return ans;
    }
};