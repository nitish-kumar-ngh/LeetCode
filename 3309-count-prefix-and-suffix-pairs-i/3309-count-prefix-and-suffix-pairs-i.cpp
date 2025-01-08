class Solution {
public:
bool isTrue(string x,string y){
    int a=x.size();
    if (y.size() < a) return false;
    string n=y.substr(0,a);
    string m=y.substr(y.size()-a,a);
    if (x==n && m==x)return true;
    else return false;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt =0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                 if (isTrue(words[i],words[j]))cnt++;
            }
        }
        return cnt;
    }
};