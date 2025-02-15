class Solution {
public:
  
    bool f(string s,int idx,int sum,int num){
        if(idx>=s.size()){
        //   cout<<sum<<" ";
            if(sum==num)return true;
            return   false;
        }
       if(f(s,idx+1,sum+int(s[idx]-'0'),num))return true;
        if(idx+2<=s.size()){
            if(f(s,idx+2,sum+stoi(s.substr(idx,2)),num))return true;
        }
        if(idx+3<=s.size()){
            if(f(s,idx+3,sum+stoi(s.substr(idx,3)),num))return true;
        }
        if(idx+4<=s.size()){
            if(f(s,idx+4,sum+stoi(s.substr(idx,4)),num))return true;
        }
        return false;
    }

    
    int punishmentNumber(int n) {
          vector<int>v(1001,0);
        int ans=0;
        for(int i=1;i<1001;i++){
            if(f(to_string(i*i),0,0,i)){
                v[i]=v[i-1]+i*i;
            }else{
                v[i]=v[i-1];
            }
        }
        // for(int i=1;i<=n;i++){
        //     if(f(to_string(i*i),0,0,i)){
        //        // cout<<i<<" ";
        //         ans+=i*i;
        //     }
        // }
        return v[n];
    }
    
};