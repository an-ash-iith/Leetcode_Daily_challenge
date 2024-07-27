class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int count=0;

        for(int i =0;i<logs.size();i++)
        {
            if(logs[i]=="../")
            {
                count--;
                count= max(count,0);
            }else if(logs[i]=="./")
            {
                //do nothing 
            }else
            {
                count++;
            }
        }
        return count;
    }
};