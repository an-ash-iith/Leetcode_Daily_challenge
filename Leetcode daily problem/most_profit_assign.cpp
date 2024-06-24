
typedef pair<int,int> pi;
class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

     //approach is like any worker will try to get greedy as any project can be chosen many number if time
     //second i will sort thr worker on basisi of difficulty --
     //assign the one with highest ptofit and will check it can be taken or not if not pop till ---

        priority_queue<pi> pq;
        int m = profit.size();
        int n = worker.size();

        for(int i =0 ;i<m;i++)
        {

          pq.push({profit[i],difficulty[i]});

        }

        sort(worker.begin(),worker.end(),greater<int>());

        int profit1=0;

        for(int i =0;i<n;i++)
        {
           int temp= worker[i];


           while(!pq.empty()  && pq.top().second>temp)
           {
               pq.pop();
           }

           if(pq.empty())
           break;

           profit1+=pq.top().first;

        }

        return profit1;
    }
};