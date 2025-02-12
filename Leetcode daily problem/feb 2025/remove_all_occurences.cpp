class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        //it could have been best done by stack  if part was a single letter --- 
        //but due to word you have to apply the brute force --- 

        int n = s.length();
        int k = part.length();
        
        int ind = s.find(part);

        while(ind != string::npos)
        { 
            string temp = s.substr(0,ind) + s.substr(ind+k,s.length()-(ind+k) +1);
            s = temp;
            ind = s.find(part);
        }

        return s;
    }
};