class Solution {
public:

    class Bitrie{
    public:
     Bitrie*left;
     Bitrie*right;
   Bitrie(){
    left = NULL;
    right = NULL;
   }
   };

   void insert(Bitrie*root,int num){

    Bitrie*temp =root;
    for(int i =31;i>=0;i--){
        int ithbit = num&(1<<i);
        if(ithbit==0){
            if(temp->left==NULL){
                temp->left = new  Bitrie();
               
            }
             temp = temp->left;
        }else{
            if(temp->right==NULL){
                temp->right = new  Bitrie();
               
            }
             temp = temp->right;
        }
    }


   }

   int f ( Bitrie*root,int num){
    int mx = 0;
    Bitrie*temp = root;
    for(int i=31;i>=0;i--){
        int ithbit = num&(1<<i);
        if(ithbit==0){
            if(temp->right!=NULL){
                mx+=pow(2,i);
                temp=temp->right;
            }else{
                temp=temp->left;
            }

        }else{
              if(temp->left!=NULL){
                mx+=pow(2,i);
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
    }
    return mx;

   }
    
    int findMaximumXOR(vector<int>& nums) {
    Bitrie*root = new  Bitrie();

    for(int i=0;i<nums.size();i++){
        insert(root,nums[i]);
    }

    int ans =0;

    for(int i =0;i<nums.size();i++){
        ans=max(ans,f(root,nums[i]));
    }
     
    
        
       return ans; 
    }
};