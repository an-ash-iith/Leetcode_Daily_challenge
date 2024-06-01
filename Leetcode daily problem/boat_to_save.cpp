class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());

        int n = people.size();
        
        int first =0;
        int second = n-1;
        int count =0;

        while(first<second)
        {

            if((people[first]+people[second])<=limit)
            {
                
                first++;
                second--;
            }
            else
            {
                second--;
            }

            count++;
        }

        if(first==second) count++;

        return count;
    }
};