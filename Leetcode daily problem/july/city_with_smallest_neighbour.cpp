class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
          
	    vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
         for (int i = 0; i < n; ++i) {
            matrix[i][i] = 0;
        }
        for(auto it: edges)
       { matrix[it[0]][it[1]]=it[2];matrix[it[1]][it[0]]=it[2];}
	    
	    for(int i =0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            for(int k=0;k<n;k++)
	            {
	                if(matrix[j][i]!=INT_MAX && matrix[i][k]!=INT_MAX)
	                 matrix[j][k] =min(matrix[j][k], matrix[j][i]+matrix[i][k]);
	            }
	        }
	    }

        int count=n;
        int ans=-1;

         for(int j=0;j<n;j++)
	        {   
                int temp=0;

	            for(int k=0;k<n;k++)
	            {
	                if(matrix[j][k]<=distanceThreshold)temp++;
	            }

                if(temp<=count)
                {
                    count=temp; ans= j;
                }
	        }
            cout<<count<<" ";
            return ans;
	    
    }
};