class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //lets apply the merger sort --
       
       int n = nums.size();
       recurse(0,n-1,nums);
        return nums;
    }


void recurse(int i , int j, vector<int> &nums)
{
    if(i>=j) return;

    int mid = (i+j)/2;

    recurse(i,mid,nums);
    recurse(mid+1,j,nums);

    //lets start merge --- 

    int first=i;
    int second= mid+1;
    vector<int> temp;
    
      //we go both the array in sorted order --

    while(first<=mid && second<=j)
    {
          // inplace merging can be done to avoid extra space complexity --
          //but is a bit complexed -
          if(nums[first]<=nums[second])
         {
            temp.push_back(nums[first]);
            first++;
          }else
          {
            temp.push_back(nums[second]);
            second++;
          }
          
    }

    while(first<=mid) {temp.push_back(nums[first]); first++;}
    while(second<=j) {temp.push_back(nums[second]); second++;}  
    

    for(auto it: temp)
    {
        nums[i]=it;i++;
    }    

    }
};