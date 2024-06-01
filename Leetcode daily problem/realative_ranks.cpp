class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        map<int,int,greater<int>> mp;

        for(int i =0;i<score.size();i++)
        {
            mp[score[i]]=i;
        }

       vector<string> ans(score.size());
       int count =0;

        for(auto &it :mp)
        {  
            count++;

            if(count==1)
            ans[it.second]="Gold Medal";
            else if(count==2)
            {
                ans[it.second]="Silver Medal";
            }else if (count==3)
            {
                  ans[it.second]="Bronze Medal";                         
            }
            else
               ans[it.second]=to_string(count);                         

        }
        return ans;
    }
};