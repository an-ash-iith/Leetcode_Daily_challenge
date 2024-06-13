class Solution {
public:
    void sortColors(vector<int>& nums) {

     //this algorithm is also known as dnf sort

     int first=0;
     int n = nums.size();
     
     int last= n-1;
     //if found element 0 then will move forward and increse the first pointer by swapping

     // if found the 2 move to the last by swapping and moving last pointer before

     //if found = 1 not do any thing
     int i =0;
     while(i<n && i<=last)
     {
         if(nums[i]==0)
         {
            swap(nums[first], nums[i]);
            first++;
            i++;
            
         }else if(nums[i]==2)
         {
            swap(nums[last], nums[i]);
            last--;
         }
         else 
         {
            i++;
         }
     }


    }
};