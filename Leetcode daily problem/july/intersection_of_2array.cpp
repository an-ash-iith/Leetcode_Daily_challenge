class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //its easy only 

        //it can also done using unordered map -- like just keep track in one
        //and traverse second -- if found print and decrease the count by 1 --

      vector<int>v1(1001,0);
      vector<int>v2(1001,0);

        for(int i=0;i<nums1.size();i++)
        {
            v1[nums1[i]]++;
        }

         for(int i=0;i<nums2.size();i++)
        {
            v2[nums2[i]]++;
        }

        for(int i =0;i<=1000;i++)
        {
          v1[i]= min(v1[i],v2[i]);
        }

        vector<int>ans;

        for(int i =0;i<=1000;i++)
        {
            for(int j=0;j<v1[i];j++)
            ans.push_back(i);
        }

        return ans;
    }

    //follow up 

    //if given array is already sorted then just played with two pointer
    //first in array and second in array 2

    //keep moving when one is smaller than other
    //if equal push int ans 
    //else greater then stop first one and move second one

    //if nums1 has smaller size then use unorderd map keeping count of element of nums1
    //traverse nums2 it may be possible that you end up exhausting all the element in the map well before the whole traversal

    //third one -- inplace sort it and use two pointer -- can be done in 0(n)
};