class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        //lets first create count array till k
        
        int n = nums.size();

        vector<int>arr(n,0);
       
        int count=0;

        for(int i =0;i<=n-k;i++)
        {    
             if(i<k){
             if(count%2) nums[i]=1-nums[i];
             }
             else
             {
                 if((arr[i-1]-arr[i-k])%2) nums[i]=1-nums[i];
             }

             if(nums[i]==0) count++;

             arr[i]=count;
        }

cout<<count<<endl;
        for(int i = n-k+1;i<n;i++)
        {
            if(i-k>=0){
            if((arr[n-k]-arr[i-k])%2)nums[i]=1-nums[i];
            }
            else
            {
            if((arr[n-k]%2))nums[i]=1-nums[i];

            }
            if(nums[i]==0)return -1;}
        
     return count;
    }
};