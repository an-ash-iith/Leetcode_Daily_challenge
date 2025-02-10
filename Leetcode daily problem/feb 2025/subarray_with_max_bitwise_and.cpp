class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int maxi = *max_element(nums.begin(),nums.end());

        int count =0;
        int total = 1;

        for(int i =0;i<n;i++)
        {
            if(nums[i]==maxi) count++;
            else 
            {
                 total= max(total,count);
                 count=0;         
            }
        }
    
      total= max(total,count);


        return total;
    }
};