
class Solution {
public:

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> row(n);
        vector<vector<int>> col(m);

        for(int i =0;i<n;i++)
        {   
            int mini=INT_MAX;
            int coli;

            for(int j =0;j<m;j++)
            {

                if(mini>matrix[i][j])
                {
                    mini = matrix[i][j];
                    coli = j;
                }
                  
            }

           row[i].push_back(mini);
           row[i].push_back(coli);
          
        }

         for(int i =0;i<m;i++)
        {   
            int mini=0;
            int rowi;

            for(int j =0;j<n;j++)
            {

                if(mini<matrix[j][i])
                {
                    mini = matrix[j][i];
                    rowi = j;
                }
                  
            }

           col[i].push_back(mini);
           col[i].push_back(rowi);
        }

   int count =0;

vector<int> ans;
        for(int i =0;i<n;i++)
        {   
                int element = row[i][0];
            

            for(int j =0;j<m;j++)
            {
                     if(element == col[j][0] && i==col[j][1] && j == row[i][1])ans.push_back(element);
            }
        }

         return ans;
    }
};

