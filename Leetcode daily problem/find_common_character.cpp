class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        vector<unordered_map<char,int>> v(n);


        for(int i =0;i<n;i++)
        {
            for(int j=0;j< words[i].size();j++)
            {
                char temp = words[i][j];
               v[i][temp]++;
            }

        }

        vector<string> ans;


         for(int j = 0; j < 26; j++) {
        char ch = 'a' + j;
        int count = INT_MAX;

        // Finding the minimum frequency of each character
        for(int i = 0; i < n; i++) {
            if(v[i].find(ch) != v[i].end()) {
                count = min(count, v[i][ch]);
            } else {
                count = 0;
                break;
            }
        }

        for(int k =0;k<count;k++)
        {
            ans.push_back(string(1,ch));
        }

         }

        return ans;
    }
};