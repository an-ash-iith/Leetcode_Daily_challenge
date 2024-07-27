class Solution {
public:
    int findTheWinner(int n, int k) {
        

        //lets use the data structure queue 

        queue<int> q;

        for(int i =0;i<n;i++) q.push(i+1);

        while(q.size()!=1)
        {
            int kill=k;
             
             while(kill>1)
             {  
                int top = q.front();
                q.pop();
                q.push(top);
                kill--;
             }

             q.pop();

        }

        return q.front();
    }
};