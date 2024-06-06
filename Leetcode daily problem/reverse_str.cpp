class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int first =0;
        int second = s.size()-1;
       
       char temp;
        while(first<second)
        {
            temp= s[first];
            s[first]=s[second];
            s[second]=temp;

            first++;
            second--;
        }

        
    }
};