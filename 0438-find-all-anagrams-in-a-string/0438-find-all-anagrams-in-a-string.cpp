class Solution {
public:
       bool allZero( vector<int>&Counter){
        for (int i=0;i<Counter.size();i++){
             if (Counter[i]!=0)return false;
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
        vector<int>result;
           vector<int>Counter(26,0);
	    for (int i=0;i<pat.size();i++){
	        Counter[pat[i]-'a']++;//frequency
	    }
	    
	    int n=txt.size();
	    int k=pat.size();
	    int i=0;
	    int j=0;
	    int ans=0;
	    while(j<n){
	        Counter[txt[j]-'a']--;
	        if (j-i+1==k){
	            if (allZero(Counter))result.push_back(i);
	       
	            Counter[txt[i]-'a']++;
	                 i++;
	        }
	        j++;
	    }
	    
	    return result;
    }
};