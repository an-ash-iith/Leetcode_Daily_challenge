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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
    

     traverse(root,target);
     return root;

    }

    void traverse(TreeNode* &node,int target)
    {
        if(node==NULL)
        return;

        if(node->left==NULL && node->right==NULL && (node->val==target))
        {
            node=NULL;
            return;
        }

        traverse(node->left,target);
        traverse(node->right,target);

        if(node->left ==NULL && node->right ==NULL && node->val==target)
        {
            node=NULL;
            return;
        }

    }
};