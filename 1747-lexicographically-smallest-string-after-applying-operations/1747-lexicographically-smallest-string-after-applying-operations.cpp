class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string>q;
        unordered_set<string>vis;

        q.push(s);
        vis.insert(s);
        string ans =s;
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            if(it<ans){
                ans=it;
            }
             string temp = it;
            for(int i=1;i<it.size();i+=2){
                temp[i] = char(((it[i]-'0')+a)%10 +'0');

            }
            if(vis.find(temp)==vis.end()){
                vis.insert(temp);
                q.push(temp);
            }
            reverse(it.begin(),it.end());
            reverse(it.begin(),it.begin()+b);
            reverse(it.begin()+b,it.end());
            
            if(vis.find(it)==vis.end()){
                vis.insert(it);
                q.push(it);
            }
            

        }
        return ans;
    }
};