
class DisjointSet{
public:
vector<int>parent;
vector<int>size;
DisjointSet(int n){
    parent.resize(n,0);
    size.resize(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
        size[i]=1;
    }
}
int find_parent(int x){
    if(x==parent[x])return x;
    return parent[x]=find_parent(parent[x]);
}
void union_by_size(int u,int v){
    int ulp_u =find_parent(u);
     int ulp_v =find_parent(v);
     if (ulp_u==ulp_v)return;
     if (size[ulp_u]>size[ulp_v]){
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
     }else{
         parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
     }
}



};








class Solution {
public:
int cnt=0;
    int largestIsland(vector<vector<int>>& grid) {
        int  n= grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]==1 ){
                       int row=i;
                       int col=j;
                       vis[row][col]=1;
                       int dx[]={0,1,0,-1};
                       int dy[]={1,0,-1,0};
                       for(int i=0;i<4;i++){
                        int newrow=row+dx[i];
                        int newcol=col+dy[i];
                        if (newrow>=0 && newcol>=0 &&newrow<n && newcol<m){
                            if (grid[newrow][newcol]==1){
                                int node=row*m+col;
                                int adjnode=newrow*m+newcol;
                                vis[newrow][newcol]=1;
                                if (ds.find_parent(node)==ds.find_parent(adjnode))continue;
                                ds.union_by_size(node,adjnode);
                            }
                        }
                       }
                }
            }
        }


            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 set<int>s;
                if (grid[i][j]==0){
                    int ans=0;
                       int row=i;
                       int col=j;
                       
                       int dx[]={0,1,0,-1};
                       int dy[]={1,0,-1,0};
                       for(int i=0;i<4;i++){
                        int newrow=row+dx[i];
                        int newcol=col+dy[i];
                       
                        if (newrow>=0 && newcol>=0 &&newrow<n && newcol<m){

                           if (grid[newrow][newcol]==1){
                             int node=newrow*m+newcol;
                             int ulp=ds.find_parent(node);
                               if (s.find(ulp)==s.end())  s.insert(ulp);
                            
                           }
                          
                       }
                      

                }
                 vector<int>v(s.begin(),s.end());
                       for(int i=0;i<v.size();i++){
                     //   cout<<v[i]<<" ";
                        ans+=ds.size[v[i]];
                       }
                       cnt=max(cnt,ans+1);
            }
        }
            }
            
            cout<<"|";
            int a=0;
        for(int i=0;i<n*m;i++){
           a=max(a,ds.size[i]);
            cout<<ds.size[i]<<" ";
        }
        cnt=max(a,cnt);
return cnt;
    }
};