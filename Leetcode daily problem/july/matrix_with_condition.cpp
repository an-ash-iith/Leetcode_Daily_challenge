class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowc, vector<vector<int>>& colc) {
        //i am going to apply two topoligical sort
        //and will keep the array in that order --
      
       vector<vector<int>> ans(k,vector<int> (k, 0));

       vector<int> ans1 =  toposort(rowc,k);
       vector<int> ans2 =  toposort(colc,k);

       if(ans1.size()!=k || ans2.size()!=k) return {};

       vector<vector<int>> mp(k+1,vector<int>(2,0));

       for(int i =0;i<ans1.size();i++)
       {
        mp[ans1[i]][0]=i;
       }

       for(int i =0;i<ans2.size();i++)
       {
        mp[ans2[i]][1]=i;
       }

      for(int i =1;i<=k;i++)
      {
        ans[mp[i][0]][mp[i][1]] = i;
      }

       return ans;

    }

    vector<int> toposort(vector<vector<int>> arr,int k)
    {
            //lets find the indegree of each element 

            vector<int> indeg(k+1,0);

            vector<vector<int>>adj(k+1);

            for(int i =0;i< arr.size();i++)
            {
                indeg[arr[i][1]]++;
                adj[arr[i][0]].push_back(arr[i][1]);
            }

            queue<int> q;

            vector<int> ans;
          
           for(int i =1;i<=k;i++)
           {
              if(indeg[i]==0) q.push(i);
           }
          
            while(!q.empty())
            {
                 int temp = q.front();
                 q.pop();
                 ans.push_back(temp);

                 for(int i =0;i<adj[temp].size();i++)
                 {
                    indeg[adj[temp][i]]--;
                    if(indeg[adj[temp][i]]==0) q.push(adj[temp][i]);
                 }

            }

            return ans;
    }
};