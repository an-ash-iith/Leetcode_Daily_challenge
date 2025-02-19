// class Solution {
// public:

//     void generate(int ind, int n, string &temp, string &mini,string pattern,vector<bool> &visit )
//     {
//          if(ind == n+1)
//          {
//             //check the pattern -- if its valid then find min of both 
//             // bool ok = true;

//             for(int i=0;i<n;i++)
//             {
//                if((pattern[i]=='I' && temp[i+1]<temp[i]) || (pattern[i]=='D' && temp[i+1]>temp[i]))
//                {
//                   return ;
//                }
//             }

//             mini = min(mini,temp);
//             return;
//          }

//          //you can keep any number at i which is not visited -- 

//          for(int i=1;i<10;i++)
//          {
//             if(!visit[i])
//             {
//                 visit[i]=1;
//                 temp+='0'+i;
//                 generate(ind+1,n,temp,mini,pattern,visit);
//                 temp.pop_back();
//                 visit[i]=0;
//             }
//          }
//     }

//     string smallestNumber(string pattern) {
        
//         //as each digit is repeated exactly ones -- 
//         //we can generate all the possible number of length pattern 
//         //this will be 10c8 *8!  = 10*10^4 -- around 10^5 which is okay --- 

//         //Q. Is there any better way to do this ? -- lets do this first ....

//         vector<string> total;
//         int n = pattern.length();
//         string mini ="a";
//         string temp ="";
//         vector<bool> visited(10,0);  
//         generate(0,n,temp,mini,pattern,visited);
//         return mini;
//     }
// };

//another method --- 
// can you proff that what ever will be pattern the answer must exist----
//let see in oppsoite way -- lets generate all the possible combination of n+1 digit
//now decode the things --- if a[i]>a[i+1] add D to string else Increaing -- 
//se we will get all the string of length n which will cover all the generated perm-- 
//it will must be there that one string will follow the given pattern -- 

//lets proof it by construction also : -- 

// 1. make a zig zag graph  {when there I mark the next point 1 index abobe and D then mark 1 index         
// bellow in y axis -}

//now assing value 0 to the first point and keep track record of min and max value seen till now 
//min 0 and max 0 and keep assigning the vaue of next point which greater than max or lower than min 
//currently and update those min and max --- 
//certainly you will get n+1 points --- all the point in one streatch or scattered-- 
//now check out the min value you achieved and add i-mini value to all those number -- 
//the sequence will follow the pattern and also each value will be in specidied range --- 


//improve my code using bitmask --- instead of vector for keeping track -- 
class Solution {
public:
    string smallestNumber(string pattern) {
        
    }
};