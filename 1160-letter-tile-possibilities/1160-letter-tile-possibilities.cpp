class Solution {
public:
set<string>ans;
   void p(string c,string temp, vector<int>&vis){
    if(temp.size()==c.size()){
        ans.insert(temp);
        return;
    }
    for(int i=0;i<c.size();i++){
        if(!vis[i]){
            string k=temp;
            temp=temp+c[i];
            vis[i]=1;
            p(c,temp,vis);
            vis[i]=0;
            temp=k;
        }
    }
   }
    void f(string &tiles,int idx,string s,set<string>&st){
        if(idx>=tiles.size()){
            st.insert(s);
            return;
        }
        f(tiles,idx+1,s+tiles[idx],st);
         f(tiles,idx+1,s,st);
    }
    int numTilePossibilities(string tiles) {
        set<string>st;
        f(tiles,0,"",st);
        vector<string>v;
        for(auto &c:st){
            v.push_back(c);
        }
        for(auto c:v){
           // v.push_back(c);
         //  vector<string>temp;
           vector<int>vis(c.size(),0);
           p(c,"",vis);
        }
        for(auto &c:ans){
           cout<<c<<" ";
        }
        return ans.size()-1;
        
    }
};