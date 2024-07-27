class Solution {
public:

    typedef pair<int,int> pi;
    long long minimumCost(string source, string target, vector<char>& orig, vector<char>& chan, vector<int>& cost) {
        
        //lets do it by graph because direct conversion is okay but one 
        //that will be made due to implication may be very complicated --

           //there is only 26 l

           vector<vector<int>> adj(26,vector<int>(26,INT_MAX));
            
            int n = orig.size();

            //lets have a directed graph ---

           for(int i=0;i<n;i++)
           {
                adj[orig[i]-'a'][chan[i]-'a'] = min(cost[i],adj[orig[i]-'a'][chan[i]-'a']);
           } 
         
           vector<vector<int>> dist;

           for(int i=0;i<26;i++)
           {
              dist.push_back(dijkstra(adj,i));
           }

           long long tcost=0;
          
          for(int i=0;i<source.size();i++)
          {
            if(dist[source[i]-'a'][target[i]-'a']!=INT_MAX)
            tcost+=dist[source[i]-'a'][target[i]-'a'];
            else return -1;
          }

          return tcost;

    }

    
    vector <int> dijkstra( vector<vector<int>> adj, int S)
    {
       
       //lets first make vector to store the maximum distance from the givne node
       
       vector<int> ans(26,INT_MAX);
       
       priority_queue<pi,vector<pi>,greater<pi>> pq;
       
       //lets push the first node --
       
       pq.push({0,S}); //first element will bt the distance and second will be the node 
       
       
    //   ans[S]=0;
       
       while(!pq.empty())
       {
           pi temp = pq.top();
           pq.pop();
           
           if(temp.first<ans[temp.second])
           {
               //go and update and push all the neighbour
               
               
               ans[temp.second]=temp.first;
               
              for(int i=0;i<adj[temp.second].size();i++)
              { 
                  if(adj[temp.second][i]!=INT_MAX)
                  pq.push({temp.first+adj[temp.second][i],i});
              }
            
            
           }
       }
       
       return ans;
        
    }
};