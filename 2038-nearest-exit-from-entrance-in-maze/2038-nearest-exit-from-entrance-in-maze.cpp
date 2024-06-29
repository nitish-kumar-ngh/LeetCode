

class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        int steps=0;

        queue<pair<int,int>>que;
        que.push({entrance[0],entrance[1]});
        //visite karo by making '+'
        maze[entrance[0]][entrance[1]]='+';

        while (que.size()>0){
             int N= que.size();
             while (N--){
              auto ele=que.front();
              que.pop();
              int i= ele.first;
              int j= ele.second;
              //boundary check
              if ((ele!= make_pair(entrance[0],entrance[1]))&& (i==0||i==m-1||j==n-1||j==0) )return steps;
              //explore the neighbours
              for (auto dir:directions){

                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if ((new_i>=0 && new_i<m && new_j>=0&&new_j<n)&& (maze[new_i][new_j]!='+')){
                    que.push({new_i,new_j});
                    maze[new_i][new_j]='+';
                }
              }




             }
             steps++;


        }
        return -1;
    }
};