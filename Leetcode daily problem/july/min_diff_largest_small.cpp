class Solution {
public:
    int minDifference(vector<int>& nums) {
        
       int n = nums.size();

        if(n<=4) return 0;

        // direct greedy won't work 

        //we have to see every combination 
        // 3 0   2 1   1 2   0 3  --- after sorting

        sort(nums.begin(),nums.end());

        //we will change ith index number to i+3 if changing from beginig 
        //and i-3 if changing from end --
         
         int ans =INT_MAX;

        // 3 0

        ans=min(ans,nums[n-1]-nums[3]);

        //2 1

        ans= min(ans,nums[n-2]-nums[2]);

        //1 2 

        ans = min(ans,nums[n-3]-nums[1]);

        //0 3

        ans= min(ans,nums[n-4]-nums[0]);
        
        return ans;

    }
};