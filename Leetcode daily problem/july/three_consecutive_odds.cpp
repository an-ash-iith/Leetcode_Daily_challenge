class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        //its easy
         int a,b,c;

         if(arr.size()<=2) return false;
        
        for(int i =0;i<arr.size()-2;i++)
        {
           a= arr[i];b=arr[i+1];c=arr[i+2];

           if(a&1 && b&1 && c&1) return true;
        }

        return false;
    }
};