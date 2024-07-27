class Solution {
public:
   static bool compare(const int &left,const int &right){return left>right;}
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, function<bool(int, int)>> mp(compare);
        vector<string> ans;
        for(int i =0;i<names.size();i++) mp[heights[i]]=names[i];
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
};


