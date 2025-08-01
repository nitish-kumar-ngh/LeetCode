class Solution {
public:
    vector<vector<int>>ans;
    void merge(vector<vector<int>>& meetings){
        sort(meetings.begin(),meetings.end());
      
        for(int i=0;i<meetings.size();i++){
            if(ans.size()==0 || ans.back()[1]<meetings[i][0]){
                ans.push_back(meetings[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],meetings[i][1]);
            }
        }
         
    }
    int countDays(int days, vector<vector<int>>& meetings) {
       merge(meetings);
       int end=0;
       int answer =0; 
       
      for(int i=0;i<ans.size();i++){
         answer=answer+ans[i][0]-end-1;
         end=ans[i][1];
        
      }
     answer=answer+days-end;
      return answer;
    }
};