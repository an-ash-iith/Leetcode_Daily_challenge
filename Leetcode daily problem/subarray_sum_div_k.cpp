class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        //lets create presome array --
        cout<<-2%5<<endl;
        int n = nums.size();

        vector<int> pre(n,0);
        unordered_map<int,int>mp;
        mp[0]=1;

        pre[0]=nums[0]%k;

        if(pre[0]<0) pre[0]+=k;
        mp[pre[0]]++;

        int count=0;

        if(pre[0]==0) count++;

        for(int i =1;i<n;i++)
        {
            pre[i]=(nums[i]%k+pre[i-1])%k;
            if(pre[i]<0) pre[i]+=k;
            count+=mp[pre[i]];
            mp[pre[i]]++;
        }

        return count;
    }
};