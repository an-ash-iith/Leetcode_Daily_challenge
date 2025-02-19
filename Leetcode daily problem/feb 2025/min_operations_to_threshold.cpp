class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();
        multiset<long long> st;

        for (auto it : nums)
            st.insert(it);

        // try to simulate ---
        int count = 0;
        while (*st.begin() < k) {
            long long a = *st.begin();
            st.erase(st.begin()); // Erase the first element

            long long b = *st.begin();
            st.erase(st.begin()); // Erase the second element

            st.insert(min(a, b) * 2 + max(a, b));
            count++;
        }
        return count;
    }
};