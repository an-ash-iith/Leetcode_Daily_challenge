#define ll long long 
class Solution {
public:
    bool judgeSquareSum(int c) {
        
        //binary search is coming --- 
        // we can do this by guessing each number --
        //bettet to guess optimally using binary search ---
        //  ***  try this question using two pointer approach ------- one at 0 and one at last equla to sqrt(n)


        for(ll i =0;i*i<=c;i++)
        {
         
         ll need = c-i*i;

            if(search(0,c,need))
            return true;
        }

        return false;
    }


    bool search(long long start,long long end,long long need)
    {

        if(start>end) return false;
        
        ll mid= (start+end)/2;

        if(mid*mid == need) return true;
     
         bool found = false;

        if(mid*mid>need)  //discard upper half ---
        {
            found|=search(start,mid-1,need);
        }else
        {
            found|=search(mid+1,end,need);
        }

        return found;
    }
};