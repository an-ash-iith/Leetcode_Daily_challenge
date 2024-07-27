class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //lets use stack -- 
        //will be greedy kill with higher one then less --
        //can be proved abab --- ba,ab  > ab,ab    if(val(ba))>val(ab)

        stack<char> st;
        int maxi=0;

        if(y>x)
        {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
            {
                if(!st.empty() && st.top()=='b') {maxi+=y; st.pop();}
                else st.push(s[i]);

            }else 
            {
                st.push(s[i]);
            }
        }
         
         stack<char>st2;

         while(!st.empty())
         {
              if(st.top()=='a')
            {
                if(!st2.empty() && st2.top()=='b') {maxi+=x; st2.pop();}
                else st2.push(st.top());

            }else 
            {
                st2.push(st.top());
            }

            st.pop();

         }
        }
        else
        {

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')
            {
                if(!st.empty() && st.top()=='a') {maxi+=x; st.pop();}
                else st.push(s[i]);

            }else 
            {
                st.push(s[i]);
            }
        }
         
         stack<char>st2;
         while(!st.empty())
         {
              if(st.top()=='b')
            {
                if(!st2.empty() && st2.top()=='a') {maxi+=y; st2.pop();}
                else st2.push(st.top());

            }else 
            {
                st2.push(st.top());
            }

            st.pop();

         }

        }


        return maxi;
    }
};