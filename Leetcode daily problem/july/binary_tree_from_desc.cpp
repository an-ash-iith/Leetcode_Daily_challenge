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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        
        //once we find the root then after that its easy -- 
        //but without it also its easy only --
         //easy way is to keep track of node and their address

         unordered_map<int,TreeNode*> mp;
         
         unordered_map<int,int> parent1;

         TreeNode* root=NULL;

          for(int i =0;i<des.size();i++)
          {
             int parent = des[i][0];
             int child= des[i][1];
             int dir = des[i][2];

             parent1[child]=parent;

               TreeNode * node;

             if(mp.find(parent)!=mp.end())
             {
                 node = mp[parent];

             }else
             {
                   node = new TreeNode(parent);
                   mp[parent]= node;
             }

               if(dir)
                {   
                      if(mp.find(child)==mp.end())
                      {
                         node->left= new TreeNode(child);
                         mp[child]=node->left;

                      }else
                      {
                        node->left=mp[child];
                      }
                
                }else
                {
                    if(mp.find(child)==mp.end())
                      {
                       node->right = new TreeNode(child);
                       mp[child]= node->right;
                      }else
                      {
                        node->right=mp[child];
                      }
                      
                }
            
              if(node->left==root || node->right==root)
                {
                    root=node;
                }
            }

            while(!(parent1.find(root->val)==parent1.end()))
            {
                root = mp[parent1[root->val]];
            }


            return root;

          }

    
};
