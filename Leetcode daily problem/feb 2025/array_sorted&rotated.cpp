class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count =0;

        int n = nums.size();
        int first = nums[0];
        bool found =false;

        for(int i =1;i< n ;i++)
        {
            if(nums[i]<nums[i-1])
            {count++;
             
            }
        }

        if(count>1)return false;
        else if(count==1)
        {
            if(nums[0]<nums[n-1])
            return false;
            else
            return true;

        }else
        {
            return true;
        }
    }
};