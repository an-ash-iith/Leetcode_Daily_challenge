class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        //lets make two prefix sum --

        int n = nums.size();

        vector<int> start(n,0);
        vector<int> end(n,0);
        unordered_map<int,int> mp;
        unordered_map<int,int> index;

        start[0]=nums[0];
        mp[0]=1;
        index[0]=-1;
        mp[start[0]%k]=1;

        for(int i =1;i<n;i++)
        {
            start[i]=start[i-1]+nums[i];

            if(mp.find(start[i]%k)==mp.end())
           { index[start[i]%k]=i;
             mp[start[i]%k]++;
           }

            if(i-index[start[i]%k]>1)
            mp[start[i]%k]++;
        }

       //keep all the remaider in an unourdered map and check -- if any two element is there which have same remainder -----

       for(auto it : mp)
       {
        if(it.second>1)
        {
            return true;
        }
       }

       return false;
    }
};