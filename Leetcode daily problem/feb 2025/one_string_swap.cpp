class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        // take one as reference --

        if (s1 == s2)
            return true;

        int swp = 0;

        // string should very at exactly 2 positon such that intercahging those
        // should handle

        int n = s1.size();
        string t1, t2;
        
        for (int i = 0; i < n; i++) {
          
            if (s1[i] != s2[i]) {
                swp++;
                t1 += s1[i];
                t2 += s2[i];
            }

            if (swp > 2)
                return false;
        }

        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());

        return t1==t2;
    }
};