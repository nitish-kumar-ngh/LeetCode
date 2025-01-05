class Solution {
public:
    long long calculateScore(string s) {
      //   int i=0;
      //   int j=0;
      // long long   int ans=0;
        // while(i<s.size()){
        //     cout<<s[i]-'a'+s[j]-'a'<<" ";
        //     if ((int(s[i]-'a')+int(s[j]-'a'))==25){
                
        //         ans+=i-j;
        //         i++;
        //         j++;
        //     }
        //     i++;
        // }
        // return ans;
    //     vector<int>vis(s.size(),0);
    //     for(int i=0;i<s.size();i++){
    //         for(int j=i+1;j<s.size();j++){
    //             if (vis[i]==0 && vis[j]==0){
    //             if ((int(s[i]-'a')+int(s[j]-'a'))==25){
    //                if (vis[i]==0 && vis[j]==0) ans+=j-i;
    //                 cout<<"("<<i<<" "<<j<<")";
    //                 vis[i]=1;
    //                 vis[j]=1;
    //                 break;
    //             }
                    
    //             }else{
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
        
    // int n = s.size();
    // int i = 0, j = 0;
    // long long ans = 0;

    // while (i < n) {
    //     if (j < i && (s[i] - 'a') + (s[j] - 'a') == 25) {
    //         // Match found
    //         ans += i - j;
    //         j++; // Move j to the next position
    //     } else if (j == i || (s[i] - 'a') + (s[j] - 'a') < 25) {
    //         // Increment i to explore further
    //         i++;
    //     } else {
    //         // No match, increment j to reduce the pair
    //         j++;
    //     }
    // }

    // return ans;

// stack<int> st[26];     long long score = 0;

//     for (int i = 0; i < s.size(); i++) {
//         int curr = s[i] - 'a'; 
//         int mirror = 25 - curr; // Mirror character index
        
//         // Check if there's a mirror character index available in the stack
//         if (!st[mirror].empty()) {
//             int j = st[mirror].top(); // Closest unmarked index
//             st[mirror].pop();         // Remove it from the stack
//             score += i - j;           // Add the score
//         } else {
//             // Push current index to the stack
//             st[curr].push(i);
//         }
//     }

//     return score;


  unordered_map<char, priority_queue<int>> map;
        int n = s.length();
        vector<bool> vis(n, false);
        long ans = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int a = c - 'a';
            char mirror = 'z' - a;
            
            if (map.find(mirror) != map.end()) {
                int b = map[mirror].top();
                map[mirror].pop();
                ans += i - b;
                if (map[mirror].empty()) {
                    map.erase(mirror);
                }
            } else {
                if (map.find(c) == map.end()) {
                    map[c] = priority_queue<int>();
                }
                map[c].push(i);
            }
        }
        return ans;



     }
};