class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<int>str1;
        vector<int>str2;
       
        string temp;

        for(int i =0;i<version1.size();i++)
        {
            
            if(version1[i]=='.')
            {
                str1.push_back(stoi(temp));
                temp="";
            }else
            {
                temp=temp+version1[i];
            }
        }

        str1.push_back(stoi(temp));

        temp="";

        for(int i =0;i<version2.size();i++)
        {
            
            if(version2[i]=='.')
            {
                str2.push_back(stoi(temp));
                temp="";
            }else
            {
                temp=temp+version2[i];
            }
        }
        
        str2.push_back(stoi(temp));

        int n = str1.size();
        int m=str2.size();

        for(int i =0;i<min(n,m);i++)
        {
            if(str1[i]<str2[i]) return -1;

            if(str1[i]>str2[i]) return 1;
        }

       
       if(n>m)
       {
        for(int i = m;i<n;i++)
        {
            if(str1[i]>0) return 1;
        }
       }
       else if(m>n)
        {
         for(int i = n;i<m;i++)
        {
            if(str2[i]>0) return -1;
        }

        }

        return 0;
       
    }
};