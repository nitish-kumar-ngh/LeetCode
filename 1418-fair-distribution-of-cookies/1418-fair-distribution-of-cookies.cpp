class Solution {
public:
    int result=INT_MAX;
    void f(vector<int>& cookies,vector<int>& child,int idx,int k){
        if (idx>=cookies.size()){
            int unfairless=*max_element(child.begin(),child.end());
            result=min(result,unfairless);
            return;
            }
            for(int i=0;i<k;i++){
                child[i]+=cookies[idx];
                f(cookies,child,idx+1,k);
                child[i]-=cookies[idx];
            }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        f(cookies,child,0,k);
        return result;
    }
};