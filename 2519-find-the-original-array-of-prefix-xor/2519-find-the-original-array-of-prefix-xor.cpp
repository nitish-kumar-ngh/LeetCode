class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> answer;
        answer.push_back(pref[0]);
        for(int i=0;i<pref.size()-1;i++){
               answer.push_back(pref[i]^pref[i+1]);
        }
        return answer;
    }
};