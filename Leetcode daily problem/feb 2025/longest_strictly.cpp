class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int linc=1;
        int ldec=1;
        
        int temp=1;
        for(int i=1;i<n;i++)
        {
             if(nums[i]>nums[i-1])
             {
                 temp++;
             }else
             {  
                 linc=max(linc,temp);
                  temp=1;
             }
        }
         linc=max(linc,temp);
        
            temp=1;
        for(int i=1;i<n;i++)
        {
             if(nums[i]<nums[i-1])
             {
                 temp++;
             }else
             {
                 ldec=max(ldec,temp);
                 temp=1;
             }
        }
        ldec=max(ldec,temp);
        
        return max(linc,ldec);
    }
};