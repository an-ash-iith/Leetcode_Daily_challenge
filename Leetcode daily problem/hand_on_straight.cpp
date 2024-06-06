class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

         int m = hand.size();

        if(m%groupSize!=0) return false;

        // priority_queue<int, vector<int>> pq;

        map<int,int> mp;

        for (int i = 0; i < m; i++) {
            
              mp[hand[i]]++;
        }   
      

      for (auto it: mp)
      {
        if(mp[it.first]>0)
        {   
            int current = it.first;
            for(int j=1;j<groupSize;j++)
            {
                mp[current+j]-=mp[current];

               if(mp[current+j]<0)
               return false;
            }
        }
      }
         
         return true;
    }
};


//    bool isNStraightHand(vector<int>& hand, int groupSize) {

//          int m = hand.size();

//         if(m%groupSize!=0) return false;

//         priority_queue<int, vector<int>> pq;

//         unordered_map<int,int> mp;

//         for (int i = 0; i < m; i++) {
            
//                 mp[hand[i]]++;
//         }

//         int p = mp.size();

//         set<int> st;

//         for(int i=0;i<m;i++)
//         {
//             st.insert(hand[i]);
//         }

//         int count = 0;
    
       
//         set<int>::iterator it = st.begin();
//         int prev= *it;
//         mp[prev]--;
//         st.erase(prev);

//         vector<int> temp(groupSize);
//         temp[0]=prev;

//         while (!st.empty()) {
         
//         count++;

//         // int curr = st.top();
//          set<int>::iterator it = st.begin();
//           int curr= *it;
//             st.erase(curr);
        
//         temp[count]=curr;

//         if(curr==prev+1)
//         {   
//             mp[curr]--;
//             prev=curr;
//         }else
//         {
//             return false;
//         }
       
//          if(count==groupSize)
//          {
//             count=0;

//             for(int i =0;i<temp.size();i++)
//             {
//                  if(mp[temp[i]]>0) 
//                  st.insert(temp[i]);
//             }
//          }
            
//         }

//         return true;
    
        
//     }


