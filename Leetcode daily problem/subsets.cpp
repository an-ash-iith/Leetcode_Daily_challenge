class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

     vector<vector<int>> ans;
     vector<int> temp;
     int n = nums.size();

     recurse(nums,n,temp,ans,0); 

     return ans;
    }

    void recurse(vector<int> & nums,int n , vector<int> temp,vector<vector<int>> &ans,int index)
    {
        if(index>n-1)
        {
            ans.push_back(temp);
            return;
        }

       //not to take 
        recurse(nums,n,temp,ans,index+1);

        //to take
        temp.push_back(nums[index]);
        recurse(nums,n,temp,ans,index+1);
    }
};