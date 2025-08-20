class Solution {
public:
   int answer=INT_MIN;
    int f(vector<vector<int>>& students, vector<vector<int>>& mentors,int idx, set<int>&s){
        if(idx==students.size()){
         return 0;
        }
        int ans=0;
        for(int i=0;i<mentors.size();i++){
            int score=0;
            if(s.find(i)==s.end()){
                s.insert(i);
                
                for(int j=0;j<students[idx].size();j++){
                        if(students[idx][j]==mentors[i][j])score++;
                    
                }
                ans=max(ans,score+f(students,mentors,idx+1,s));
                s.erase(i);
            }
        }
        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        set<int>s;
       return  f(students,mentors,0,s);
    }
};