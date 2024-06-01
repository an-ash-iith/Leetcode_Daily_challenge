class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(),happiness.end(),greater<int>());

        long long sum = 0;
        // long long sub =0;

        int count=-1;
        int sub =0;

        for(int i =0;i<k;i++)
        {
           
            if(happiness[i]>=sub)
            { sum=sum+happiness[i];
              count++;
              sub++;
            }

            
        }

        return sum - (long long )count*(count+1)/2;
    }
};