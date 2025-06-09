class Solution {
public:
    set<string>st;
     set<string>st1;


void permutation(string ste, int idx, vector<int>& vis, string &s) {
    if (idx >= ste.size()) {
        st1.insert(s);
        return;
    }
    for (int i = 0; i < ste.size(); i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            s += ste[i];             
            permutation(ste, idx + 1, vis, s);
            s.pop_back();             
            vis[i] = 0;
        }
    }
}


    
    void f(string tiles,int idx,string &s){
         if(s.size()>=1){
            st.insert(s);
        }
        if(idx>=tiles.size())return;
       
        for(int i=idx;i<tiles.size();i++){
            string d=s;
            s+=tiles[i];
            f(tiles,i+1,s);
            s=d;
        }
    }
    int numTilePossibilities(string tiles) {
        string s;

        f(tiles,0,s);
       
        vector<string>ste(st.begin(),st.end());
        for(int i=0;i<ste.size();i++){
            cout<<ste[i]<<" ";
            vector<int>vis(ste.size(),0);
            string s;
           permutation(ste[i],0,vis,s);
        }
        return st1.size();
    }
};