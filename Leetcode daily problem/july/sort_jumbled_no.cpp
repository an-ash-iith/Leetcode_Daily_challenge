class Solution {
public:
 static bool compare(pair<int,int> &a, pair<int,int> &b)
{
    return a.first<b.first;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int,int>> temp;

        for(auto it :nums)
        {
            string s = to_string(it);
            string f;

            for(int i=0;i<s.size();i++)
            {
                f+=char(mapping[s[i]-'0']+'0');
            }

            temp.push_back({stoi(f),it});
        }
         
        sort(temp.begin(),temp.end(),compare);

        vector<int> ans;

        for(auto it: temp)
        {
            ans.push_back(it.second);
        } 

        return ans;
       
    }
};