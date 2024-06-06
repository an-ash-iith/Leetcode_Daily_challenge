class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> mp;

        int n = s.length();

        for(int i =0;i<n;i++)
        {
            mp[s[i]]++;
        }

        int count =0;

        int found=false;

        for(auto &it : mp)
        {
           count+=it.second/2;

           if(it.second&1 && !found) found =true;
        }

         count=count*2;

        if(found)
        count++;

         return count;
    }
};