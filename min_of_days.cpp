class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int ans=-1;
       long long maxi = *max_element(bloomDay.begin(),bloomDay.end());

        findans(bloomDay,m,k,1,maxi,ans);
         
         return ans;
    }


 void findans(vector<int> & piles,int m ,int k, long long start,long long end, int &ans)
 {

    if(start>end) return ;

  long long mid = start+(end-start)/2;

    if(ispossible(piles,m,k,mid))
    {
       ans= mid;
       findans(piles,m,k,start,mid-1,ans);
    }
    else
    {
        findans(piles,m,k,mid+1,end,ans);
    }

 }

 bool ispossible(vector<int>&piles,int m,int k, int mid)
 {
    //yoou are finding at this rate

  
    long long count=0;
    int streak=0;

    for(int i =0;i<piles.size();i++)
    {
      

       if(piles[i]<=mid)
       {
        streak++;
       }
       else
       {
        streak=0;
       }

        if(streak==k)
       {
        count++;
        streak=0;
       }
     
    }

    if(count>=m)
    return true;

    else return false;

 }

};