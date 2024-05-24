class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    
    int n = nums.size();
    int sum=0;
    int presum=0;

     for(int i =0;i<n;i++)
     {
          presum=presum^nums[i];
     }   

     sum=presum;

     findsum(nums,n-1,sum,presum,0);

     return sum;
    }

    void findsum(vector<int> &nums,int index,int &sum,int presum,int start)
    {
        if(index==0)return;

        for(int i =start;i<nums.size();i++)
        {
            sum+=nums[i]^presum;

            findsum(nums,index-1,sum,presum^nums[i],i+1);
        }
    }
};