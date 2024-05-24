class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        //lest apply dp -- like either to chose that word or not //as there will be 26 letters so make a 2d vector -- that will keep
        //record of the number of character needeed -- if it is possible to allot that many -- give else not going to chose that word 
            int n = words.size();
            vector<int> count(26,0);

            for(int i =0;i<letters.size();i++)
            {
               count[letters[i]-'a']++;
            }

            string temp;

           vector<vector<int>> dp(n,vector<int>(26,0));
           vector<int> point(n,0);

             for(int i =0;i<n;i++)
             {
               temp = words[i];
               int val=0;

                for(int j=0;j<temp.size();j++)
                {
                   dp[i][temp[j]-'a']++;
                   val+=score[temp[j]-'a'];
                }
                point[i]=val;
              }

             int max=0;

           recurse(words,dp,count,point,0,n,0,max);

           return max;
        
    }


    void recurse(vector<string>& words,vector<vector<int>> &dp,vector<int>count,vector<int>&point,int index,int n , int current  ,int &max)
    {
        if(index>=n)
        {
            if(current>max)
            max= current;

            return ;
        }
        

                //not going to take this
        recurse(words,dp,count,point,index+1,n,current,max);
        //it may be valid to take or not 

        if(isvalid(count,dp[index])==true)
        {
            //goint to take this 
             for(int i=0;i<26;i++)
             {
                count[i]=count[i]-dp[index][i];
             }
            
            recurse(words,dp,count,point,index+1,n,current+point[index],max);
        }
        

    }


    bool isvalid(vector<int> count,vector<int> part)
    {
        for(int i=0;i<26;i++)
        {
            if(count[i]<part[i]) return false;
        }

        return true;
    }
};