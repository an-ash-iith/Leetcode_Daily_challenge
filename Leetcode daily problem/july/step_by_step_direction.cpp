/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string getDirections(TreeNode* root, int st, int en) {
        
        // there is the easy method than finding parent 

        TreeNode * head =root;

        string ans1;
        string ans2;

        vector<string> ans(2);

        traversal(head,ans1,ans2,ans,st,en);

        string temp;

        ans1= ans[0];
        ans2= ans[1];
        int i=0,j=0;

        cout<<ans1<<" "<<ans2<<endl;
        while(i<ans1.size() && j<ans2.size())
        {
            if(ans1[i]!=ans2[j])
            {
                break;
            }
            else
            {
                ans1.erase(i,1);
                ans2.erase(j,1);
            }

            // i++;
            // j++;
        }
        cout<<ans1<<" "<<ans2<<endl;
        for(int i =0;i<ans1.length();i++)
        {
            temp+="U";
        }

        return temp+ans2;
    }

        void traversal(TreeNode* root,string &ans1,string &ans2,vector<string>&ans,int st,int en)
    {
        if(root==NULL) return;

        if(root->val==st) ans[0]=ans1;
        if(root->val==en) ans[1]=ans2;
        
      ans1+="L";
      ans2+="L";
        traversal(root->left,ans1,ans2,ans,st,en);
      ans1.pop_back(); ans2.pop_back();
     ans1+="R";
      ans2+="R";
        traversal(root->right,ans1,ans2,ans,st,en);
      ans1.pop_back(); ans2.pop_back();
    }
};

