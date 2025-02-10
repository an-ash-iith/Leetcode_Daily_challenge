class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
        // time limit constrained in o(n^2)  ----- 
        //as all the elements in the nums are distinct --- 
        //i will sort --- 

        sort(nums.begin(),nums.end());

        //as all the element are distict so i can claim as  a*b is val 
        // m*n is equal to val then non of m and n will be equal to a or b --(except m and n are itself a and b )

        //just apply o(n^2) algo -- 

        unordered_map<int,int> mp; //keep the count mp[val] = how many such pair are there with value val --- 

        int ans =0;
        
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               mp[nums[i]*nums[j]]++;
            }
        }

        for(auto it: mp)
        {
            ans+= (it.second * (it.second-1))*4;
        }

        return ans;
    }
};