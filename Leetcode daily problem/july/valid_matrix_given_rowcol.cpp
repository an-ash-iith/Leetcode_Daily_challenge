class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rows, vector<int>& cols) {
         
         int n = rows.size();
         int m = cols.size();

        vector<vector<int>> ans(n,vector<int>(m,0));

        int first=0;
        int second=0;

        while(first<n && second<m)
        {
            if(rows[first]==0)
            first++;

           else if(cols[second]==0)
            second++;
           else
           {
            int val = min(rows[first],cols[second]);
            rows[first]-=val;
            cols[second]-=val;
            ans[first][second]=val;
           }
        }


        return ans;
    }
};