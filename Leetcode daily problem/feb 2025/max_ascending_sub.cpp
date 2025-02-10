class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        //its very easy question -- 
        int maxi =nums[0];
        int curr = nums[0];
        
        int n = nums.size();
     
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1]) curr+=nums[i];
            else curr = nums[i];

            maxi = max(maxi , curr);
        }

        return maxi;
    }
};