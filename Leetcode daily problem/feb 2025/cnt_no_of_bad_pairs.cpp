class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        //its can be easily done in o(n^2)  --------

        //but have to do in o(n)  so lets do some preprocessing -- 

        //as we have to count how many pair are there that follow that --- 
        //rather than to do that if we do how many pair are there with j-i = nums[j] -nums[i]
        //and subtract from total such pair thai nc2 then we are done -- 

        // j-i = nums[j] - nums[i]  =>  nums[j] -j = nums[i] -i 
        //we will use map for this -- 

        unordered_map<int,int> mp;
        
        int n = nums.size();
        //lets preprocess the array -- 
        long long total = (1ll*n*(n-1))/2;
      
        for(int i=0;i< n;i++)
        {
          total-=mp[nums[i]-i];
          mp[nums[i]-i]++;
        }

        return total;
     }
};