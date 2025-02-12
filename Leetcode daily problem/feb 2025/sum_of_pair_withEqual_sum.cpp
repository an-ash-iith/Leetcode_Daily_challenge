class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        //it can be easily done o(n^2)--
        //but can be also done in o(n) using map --- 

        //lets keep one map of pair 

        unordered_map<int,vector<int>> mp;

        for(auto it: nums)
        {
           int sum_dig =0;
           int val = it;

           while(val>0)
           {
            sum_dig += val%10;
            val = val/10;
           }

           mp[sum_dig].push_back(it);
        }

        //now iterate through the map and find 2 largest value --- 

        int maxi = -1;

        for(auto it: mp)
        {
            if(it.second.size()<2) continue;

            sort(it.second.begin(),it.second.end(),greater<int>());
            
            maxi = max(maxi, it.second[0]+it.second[1]);
        }

        return maxi;
    }
};