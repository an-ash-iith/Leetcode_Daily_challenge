class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n= grid.size();

        vector<vector<int>> ans(n-2, vector<int> (n-2)) ;
        
        for(int i =0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)

            {
              
              ans[i][j]= find_max(i,j,grid);
            }
        }
        return ans;
    }

    int find_max(int row,int column,vector<vector<int>>& grid)
    {
        int max1=1;
        
        
        for(int i =row; i<row+3;i++)
        {
            for(int j=column;j<column+3;j++)
            {
                 if(max1<grid[i][j])
                 max1=grid[i][j];
            }
        }

        return max1;
    }
};