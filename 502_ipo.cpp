typedef pair<int, int> pi;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        

        priority_queue<int> pq;  //max heap

        int n = profits.size();

        vector<pi>v;

        for(int i =0;i<n;i++)
        {
            if(profits[i]>0)
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end()); //sorted on the basis of capital --- 


        //you currently have w as initial capital -- so keep pushing all the capital with that capital less than or equal to 
       int i =0;

        while(i<v.size())
        {
            if(v[i].first<=w)
            {
                cout<<v[i].second<<"pu";
                pq.push(v[i].second);
                i++;
            }else
            {   if(pq.empty())
                 return w;

                int top= pq.top();
                pq.pop();
                cout<<top<<"po";
                w+=top;
                k--; 
            }

            if(k==0)
            {
                return w;
            }
        }

        while(k>0 && !pq.empty())
        {
             int top= pq.top();
             pq.pop();
             cout<<top<<"po";
             w+=top;
             k--; 
        }

          return w;

    }
};