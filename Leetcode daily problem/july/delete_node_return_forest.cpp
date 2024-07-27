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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        //always keep the head when it is not getting deleted
        //delete the things from the bottom

        vector<TreeNode*> ans;
        TreeNode* head = root;

        unordered_map<int,int> mp;

        for(int i=0;i<to_delete.size();i++)
        {
            mp[to_delete[i]]=1;
        }
        
        recurse(root,NULL,-1,ans,mp);
        if(mp.find(root->val)==mp.end())
        {
            ans.push_back(root);
        }
        return ans;

    }

    void recurse(TreeNode* node ,TreeNode* prev1 ,int prev ,vector<TreeNode*> &ans,unordered_map<int,int>&mp)
    {
        if(node==NULL) return;
        
        recurse(node->left,node,0,ans,mp);
        recurse(node->right,node,1,ans,mp);

        if(mp.find(node->val)!=mp.end())
        {

            if(node->left!=NULL)
            ans.push_back(node->left);
             if(node->right!=NULL)
            ans.push_back(node->right);
            
            if(prev1!=NULL)
            {
            if(prev==0) prev1->left=NULL;
            
            if(prev==1) prev1->right=NULL;

            }
        }

    }
};