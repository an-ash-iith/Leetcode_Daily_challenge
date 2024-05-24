

class Solution {
public:
    vector<vector<int>> dp;

    Solution() : dp(16, vector<int>(16, -1)) {}

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recurse(0, 0, ans, temp, s);
        return ans;
    }

    void recurse(int i, int j, vector<vector<string>>& ans, vector<string>& temp, const string& s) {
        if (j >= s.size()) {

            if(!temp.empty() && (i==j))
            ans.push_back(temp);
            return;
        }

        if (dp[i][j] == -1) {
            dp[i][j] = check_pallindrome(i, j, s);
        }

        if (dp[i][j] == 1) {
            // not to take
            recurse(i, j + 1, ans, temp, s);

            // take it and move forward
            temp.push_back(s.substr(i, j - i + 1));
            recurse(j + 1, j + 1, ans, temp, s);
            temp.pop_back(); // undo the change to temp
        } else {
            recurse(i, j + 1, ans, temp, s);
        }
    }

    int check_pallindrome(int i, int j, const string& s) {
        while (i < j) {
            if (s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};
