class Solution {
public:
 vector<vector<int>> dp;

    Solution() : dp(20, vector<int>(20, -1)) {}
   
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        map<string,int> mp;
        
        int n = wordDict.size();

        for(int i =0;i<n;i++)
        {
            mp[wordDict[i]]++;
        }
        vector<string> ans;
        string temp;
    //  vector<vector<string>>ans;
          recurse(0,0,temp,ans,s,mp);

          return ans;
    }

        void recurse(int i, int j, string temp , vector<string> &ans, string& s,map<string,int> mp) {
        if (j >= s.size()) {
            
            if(temp.size())
            temp.erase(0,1);

            if(temp.size() && (i==j))
            ans.push_back(temp);
            return;
        }

        if (dp[i][j] == -1) {
            dp[i][j] = check_valid(s.substr(i,j-i+1),mp);
        }

        if (dp[i][j] == 1) {
            
            recurse(i, j + 1, temp, ans,s,mp);
            string temp_s= s.substr(i, j - i + 1);
            // take it and move forward
            temp=temp +" "+temp_s;
            recurse(j + 1, j + 1, temp,ans, s,mp);
            temp.pop_back(); // undo the change to temp
        }else
        {
          recurse(i, j + 1, temp,ans, s,mp);
        }
    }

    int check_valid(string stg,map<string,int>mp )
    {
        if(mp[stg]>=1) return 1;

        else return 0;
    }
};