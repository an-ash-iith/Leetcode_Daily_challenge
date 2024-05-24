class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int ans=0;
        int n = grid.size();
        int m= grid[0].size();

        for(int i =0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
            for(int j=0;j<m;j++)
            {
              grid[i][j]=1-grid[i][j];
            }

            }
        }

     

        for(int j =0;j<m;j++)
        {
            int number =0;

            for(int i=0;i<n;i++)
            {            
              if( grid[i][j]==1)
                 number++;

            }
      
      ans=ans+(max(number,n-number)*(1<<(m-1-j)));
            
        }

        return ans;
    }
};