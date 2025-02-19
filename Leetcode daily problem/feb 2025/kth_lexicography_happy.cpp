class Solution {
public:
    typedef long long ll;

    void generate(int ind,int prev, ll temp,int n, vector<ll> &ans )
    {
        if(ind==n) 
        {
            // cout<<"hi"<<temp<<endl;
            ans.push_back(temp);
            return;
        }

        for(int i=1;i<=3;i++)
        {

        if(i==prev) continue;

        temp = temp * 10 + i;
        generate(ind+1,i,temp,n,ans);
        temp/=10;

        }
    }

    string getHappyString(int n, int k) {
        
        //simply generate all the string of length n ---
        //there are 3^10 possibility = 9^5 which is less than 10^5 
        //directly apply the brute force algo ---- also can be stored in string 
        //because vector size will be at max 10^5 * 10 = 10^6 ---
        
        //but things can improvied a lot -- rather than storing --- 
        //generate in such a way so that kth should be here --but its lil bit hard 
        

        // // also it can be modified --- like the way we are generating is lexicographically only
        // // so in the time of generating only check its kth largest or not 
        vector<long long> ans;
        //lets decode things as 1 ,2 ,3 
        
        long long temp=0;
    
        generate(0,-1,temp,n,ans);
        
       sort(ans.begin(),ans.end());
    //    cout<<ans.size()<<"sss ";

        if(ans.size()>=k) 
        {
            string s;
            // cout<<"ho"<<endl;
            temp = ans[k-1];
            cout<<temp<<endl;

            while(temp>0)
            {
                s+= 'a' + temp%10 -1;
                temp = temp/10;
            }

            reverse(s.begin(),s.end());
            return s;
        }
        else 
        return "";        

    }
};