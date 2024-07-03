class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string>set;
        int x=0;
        int y=0;
        string key=to_string(x)+"_"+to_string(y);
        set.insert(key);
        for (auto ch:path){
            if (ch=='N')y++;
            else if (ch=='S')y--;
            else if (ch=='E')x++;
            else  x--;
            key=to_string(x)+"_"+to_string(y);
            if (set.find(key)!=set.end())return true;
            else set.insert(key);
        }
        return false ;
    }
};