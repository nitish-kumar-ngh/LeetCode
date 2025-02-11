class Solution {
public:
    int compress(vector<char>& chars) {
        
        char curr_char=chars[0];
        int idex=0;
        int i=0;
        int count=0;
        while(i<chars.size()){
            if (chars[i]==curr_char){
                count++;
                i++;
            }else{
                chars[idex]=curr_char;
                idex++;
                string x=to_string(count);
           
                if (count!=1){
                    for(int j=0;j<x.size();j++){
                    chars[idex]=x[j];
                    idex++;
                }}
                curr_char=chars[i];
                count=0;
            }
            if (i==chars.size()){
                  chars[idex]=curr_char;
                idex++;
                string x=to_string(count);
           
                if (count!=1){
                    for(int j=0;j<x.size();j++){
                    chars[idex]=x[j];
                    idex++;
                }}
               // curr_char=chars[i];
                count=0;
            }
        }
        return idex;
    }
};