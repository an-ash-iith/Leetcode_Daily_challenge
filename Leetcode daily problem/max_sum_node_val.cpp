class Solution {
public:
    long long dp[20001][2];

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        if (n == 0) return 0; // Edge case: empty nums array

        // Initialize dp array with -1 (indicating uncomputed states)
        memset(dp, -1, sizeof(dp));

        // Start recursion with flag as true (indicating even), index 0
        return recurse(nums, k, 1, 0);
    }

    long long recurse(vector<int> &nums, int k, int flag, int index) {
        if (index >= nums.size()) return flag == 1 ? 0 : -1e9;

        // Return precomputed result if available
        if (dp[index][flag] != -1) return dp[index][flag];

        // Compute the maximum value by considering the current element with and without XOR
        long long withXor = recurse(nums, k, 1 - flag, index + 1) + (nums[index] ^ k);
        long long withoutXor = recurse(nums, k, flag, index + 1) + nums[index];

        // Store the result in dp table and return
        dp[index][flag] = max(withXor, withoutXor);
        return dp[index][flag];
    }
};
