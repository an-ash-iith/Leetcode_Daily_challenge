class Solution {
public:
   static bool compare(const pair<int,int> &p1 , const pair<int,int> &p2)
    {
          if(p1.first==p2.first) return p1.second>p2.second;
          else return p1.first<p2.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<pair<int,int>> v1;
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i =0;i<n;i++)
        { 
            if(mp.find(nums[i])!=mp.end())
           mp[nums[i]]++;
           else
           mp[nums[i]]=1;
        }
         
         for(auto it: mp)
         v1.push_back({it.second,it.first});

         sort(v1.begin(),v1.end(),compare);


         vector<int> ans;

         for(auto it: v1)
         {
          while(it.first>0) {ans.push_back(it.second); it.first--;}

         }
        
         return ans;
    }
};
