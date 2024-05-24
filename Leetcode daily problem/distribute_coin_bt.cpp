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
    int distributeCoins(TreeNode* root) {

     //the  main idea is every parent have to take care the need of childreen else if other person or grand parent is doing will
     //be more costilier than this one -- it can be proved also

     int moves=0;

     traverse(root,moves);    

     return moves;  
    }

    // int traverse(TreeNode* node,int & moves)
    // {
    //     if(node==NULL)
    //     return 0;  //chill and enjoy


    //     int give_left = traverse(node->left,moves);
    //     int give_right = traverse(node->right,moves);
        
    //     // node->val= node->val+give_left+give_right;

  
    //     moves+=abs(give_left)+abs(give_right);
         
    //      //lets return the total burden comin on parent --children may be giving or may be taking 
    //     return  node->val+give_left+give_right-1;
    // }


    // second approach


    int traverse(TreeNode* node,int & moves)
    {
        if(node==NULL)
        return 0;  //chill and enjoy


        int give_left = traverse(node->left,moves);
        int give_right = traverse(node->right,moves);
        
        node->val= node->val+give_left+give_right;

  
        moves+=abs(node->val-1);
         
         //lets return the total burden comin on parent --children may be giving or may be taking 
        return  node->val-1;
    }
};