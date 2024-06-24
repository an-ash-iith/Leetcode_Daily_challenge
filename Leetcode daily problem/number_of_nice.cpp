class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n =nums.size();

        unordered_map<int,int> mp;

    
        int count =0;

        vector<int> pre(n);
        pre[0]=0;

        if(nums[0]&1) pre[0]=1;

       for(int i =1;i< n;i++)
        {
            pre[i]= (nums[i]&1) +pre[i-1];
         
        }

        mp[0]=1;
        for(int i =0;i<n;i++)
        {
          
            count += mp[pre[i]-k];
            mp[pre[i]]++;

        }

        return count;
    }
};