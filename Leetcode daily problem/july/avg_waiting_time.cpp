class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        

        //this is nothing but job scheduling problem 

        // sort(customers.begin(),customers.end());  //sort on basis of arrival time 

        int n = customers.size();

        double wait=0;

        int time =0;

        for(int i =0;i<n;i++)
        {
            int arr = customers[i][0];
            int bust= customers[i][1];


            time= max(time,arr) +bust;
            wait +=time-arr;
            

        }
       
       return wait/n;

    }
};