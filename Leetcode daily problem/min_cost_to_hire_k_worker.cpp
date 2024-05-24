class Solution {
public:
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> workers;

    for (int j = 0; j < n; j++) {
        double ratio = static_cast<double>(wage[j]) / quality[j];
        workers.emplace_back(ratio, quality[j]);
    }

    sort(workers.begin(), workers.end());

    priority_queue<int> maxHeap;
    int sumQuality = 0;
    double minCost = numeric_limits<double>::max();

    for (auto& worker : workers) {
        double ratio = worker.first;
        int quality = worker.second;

        sumQuality += quality;
        maxHeap.push(quality);

        if (maxHeap.size() > k) {
            sumQuality -= maxHeap.top();
            maxHeap.pop();
        }

        if (maxHeap.size() == k) {
            minCost = min(minCost, ratio * sumQuality);
        }
    }

    return minCost;
}
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
//         int n = quality.size();

//         multimap<double,int>mp;
//         multimap<int,double> qual;

//         for(int j=0;j<n;j++)
//         {   
//             double index=(double)wage[j]/quality[j];
//             mp.insert(pair<double, int>(index, j));
//             // mp[index]=j;
//             cout<<index<< " ";
//             qual.insert(pair<int, double>(quality[j],index));
//             // qual[quality[j]]=index;
            
//         }

//         cout<<endl;

// double val ;

// double min=INT_MAX;

// int worker=0;
//     for(auto it = mp.begin(); it != mp.end(); ++it) {

// worker++;
// cout<<worker<<" "<<it->first<<"no"<<endl;
// if(worker>=k)
// {   
//     val =it->first;
//  cout<<"val is "<<val<<endl;
// int count=k;
// double current=0.0;

//        for(auto it1 = qual.begin(); it1 != qual.end(); ++it1) {

//              if(count>0 && it1->second<=val)
//              {
//                 count--;
//                 current+= val*it1->first;
//              }
//        }

//        if(current<min)
//        {
//         min=current;
//        }

// }
    
// }

//         return min;
//     }

};