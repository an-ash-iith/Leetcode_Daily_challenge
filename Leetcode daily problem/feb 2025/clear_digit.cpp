class Solution {
public:
    string clearDigits(string s) {
        
        //its direct qustion of stack 

        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                st.pop();
            }
            else st.push(s[i]);
        }


        string ans;

        while(!st.empty()) 
        {
            ans+=st.top(); st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};