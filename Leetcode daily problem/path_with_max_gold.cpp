// class Solution {
// public:
//     void find_maxgold(vector<vector<int>>& grid, vector<vector<int>>& visited, int max1, int& ultimate_max, int row, int column) {  
//         int m = grid.size();
//         int n = grid[0].size();

//         if(row < 0 || row >= m || column < 0 || column >= n || visited[row][column] == 1 || grid[row][column] == 0) {
//             ultimate_max = max(max1, ultimate_max);
//             return;
//         }

//         visited[row][column] = 1;
//         max1 += grid[row][column];

//         find_maxgold(grid, visited, max1, ultimate_max, row - 1, column);
//         find_maxgold(grid, visited, max1, ultimate_max, row + 1, column);
//         find_maxgold(grid, visited, max1, ultimate_max, row, column - 1);
//         find_maxgold(grid, visited, max1, ultimate_max, row, column + 1);

//         visited[row][column] = 0;
//     }

//     int getMaximumGold(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> visited(m, vector<int>(n, 0));
//         int ultimate_max = 0;

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 int max = 0;
//                 find_maxgold(grid, visited, max, ultimate_max, i, j);
//             }
//         }
//         return ultimate_max;
//     }
// };
// class Solution {
// public:
//        void find_maxgold(vector<vector<int>>& grid,vector<vector<int>> &visited,int &max,int &ultimate_max,int row,int column)
//        {  
//        int m=grid.size();
//        int n= grid[0].size();

//            if(grid[row][column]!=0 && visited[row][column]!=1)
//                {   
//                    max+=grid[row][column];
                     
//                }
//             else 
//             {   

//               if(ultimate_max<max)
//               {
//                 ultimate_max=max;
//               }
//                 return;
//             }
             
//               visited[row][column]=1;
           
//                   if(row>0)
//                   {
//                     if(grid[row-1][column]!= 0 && visited[row-1][column]!=1)
//                     {
//                         find_maxgold(grid,visited,max,ultimate_max,row-1,column);
//                     }
//                   }

//                   if(row<m-1)
//                   {
//                     if(grid[row+1][column]!=0 && visited[row+1][column]!=1)
//                     {
//                          find_maxgold(grid,visited,max,ultimate_max,row+1,column);   
//                     }
//                   }

//                    if(column>0)
//                   {
//                     if(grid[row][column-1]!= 0 && visited[row][column-1]!=1)
//                     {
//                         find_maxgold(grid,visited,max,ultimate_max,row,column-1); 
//                     }
//                   }
                 
//                   if(column<n-1)
//                   {
//                      if(grid[row][column+1]!= 0 && visited[row][column+1]!=1)
//                      {
//                         find_maxgold(grid,visited,max,ultimate_max,row,column+1); 
//                      }
//                   }
              
//               visited[row][column]=0;
//               max=max- grid[row][column];
//        }

//     int getMaximumGold(vector<vector<int>>& grid) {
//        int m=grid.size();
//        int n= grid[0].size();

//        vector<vector<int>> visited(m, vector<int>(n, 0));

//        int max=0;
//        int ultimate_max=0;
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
            

//             if(!visited[i][j])
//             {
            
//             find_maxgold(grid,visited,max,ultimate_max,i,j);
            
//             }

//            }
//        }
     
//        return ultimate_max;
//     }
// };