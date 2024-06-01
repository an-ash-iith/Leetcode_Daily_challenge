class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int n = nums.size();

        int first = 0;
        int second = n-1;
        int ans =-1;

       while(first<=second){
    
        if(nums[first]<0 && abs(nums[first])==nums[second])
        {
            ans= nums[second];break;
        }

        if(abs(nums[first])>nums[second])
        first++;
        else 
        second--;
       }

       return ans;
    }
};