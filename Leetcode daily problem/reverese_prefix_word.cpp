class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        string ans;
        
        bool turn = true;
        for(int i =0;i<word.size();i++)
        {
            if(turn)
            {
               ans= word[i]+ans;
            }else ans= ans+word[i];

            if(word[i]==ch) turn = false;
        
        }


        if(turn == false) return ans;
        else return word;
    }
};