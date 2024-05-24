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
    bool evaluateTree(TreeNode* root) {
        
        bool ans;
       
       TreeNode * node = root;
   
   if(node==NULL)
   return true;

        ans= traverse(node);


        return ans;

    }

// simply doing postorder traversal
    bool traverse(TreeNode * node)
    {
        if(node->left==NULL && node->right==NULL)
        {
            if(node->val==0)
            return false;
            else
            return true;
        }

        if(node->val== 2)
        {
            return traverse(node->left) | traverse(node->right);
        }else
        {
            return traverse(node->left) & traverse(node->right);
        }

    }
};