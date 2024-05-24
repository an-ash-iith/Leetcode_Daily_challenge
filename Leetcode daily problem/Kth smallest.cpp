class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        vector<int> ans;

        int n = arr.size();
         int size= (n*(n-1))/2;
        
        map<double,pair<int,int>> mp;

for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {


      mp[(double)arr[i]/arr[j]]={i,j};
    }
}
    

    int count =0;
 for(auto it: mp)
 {
  
  count++;

  if(count==k)
  {
    ans.push_back(arr[it.second.first]);
ans.push_back(arr[it.second.second]);
    return ans; 
  }
 }

    return ans; 
    }
};