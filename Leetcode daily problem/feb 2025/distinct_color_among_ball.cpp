class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        
        vector<int> ans;
        
        //play with map --
        
        map<int,int> mp1,mp2;
        int count=0;
        
        //the idea is at any instant number of ball cant have size more than 10^5   
        
        for(auto it: q)
        {
            
               mp1[it[1]]++;
              
              if(mp1[it[1]]==1) count++;
            
            if(mp2.find(it[0])!=mp2.end())
            {
                //check its color --
                
                mp1[mp2[it[0]]]--;
                
                if(mp1[mp2[it[0]]]==0) count--;
            }
            
            mp2[it[0]]=it[1];
            
            ans.push_back(count);
        }
        
        return ans;
        
    }
};