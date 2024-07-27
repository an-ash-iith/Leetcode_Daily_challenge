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
// class Solution {
// public:
//     int countPairs(TreeNode* root, int distance) {
//         // Assuming that each node has a different value
//         // It's not clear because the number of nodes possible is up to 1024, but 
//         // the value is up to 100 only, so there is a chance of repetition.

//         // The idea is to make a graph so that I can easily traverse

//         unordered_map<TreeNode*, vector<TreeNode*>> edges;
//         unordered_map<TreeNode*, int> leaf;

//         recurse(root, edges, leaf);  // Getting all the edges 
//         // We are ready with leaf nodes and the adjacency list
//         int count = 0;

//         for (auto it : leaf) {
//             dfs(it.first, count, 0, edges, distance,leaf);
//         }

//         cout<<count<<endl;

//         return count / 2;
//     }

// private:
//     void dfs(TreeNode* node, int &count, int dist, unordered_map<TreeNode*, vector<TreeNode*>> &edges, int distance ,unordered_map<TreeNode*, int> &leaf) {
//         if (dist > distance) return;

//         vector<TreeNode*> nbour = edges[node];  


//         for (auto it : nbour) {  
//             if (it != node)
//             {
//              if (leaf[it] == 1 && dist+1<=distance) count++;  
//                 dfs(it, count, dist + 1, edges, distance,leaf);

//             }
//         }
//     }

//     void recurse(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &edges, unordered_map<TreeNode*, int> &leaf) {
//         if (root == NULL) return;

//         if (root->left == NULL && root->right == NULL) {  // It's a leaf node
//             leaf[root] = 1;
//             return;
//         }

//         if (root->left != NULL) {
//             recurse(root->left, edges, leaf);
//             edges[root].push_back(root->left);
//             edges[root->left].push_back(root);
//         }

//         if (root->right != NULL) {
//             recurse(root->right, edges, leaf);
//             edges[root].push_back(root->right);
//             edges[root->right].push_back(root);
//         }
//     }
// };

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> edges;
        unordered_map<TreeNode*, bool> leaf;

        // Get all the edges and leaf nodes
        recurse(root, edges, leaf);

        int count = 0;

        for (auto it : leaf) {
            if (it.second) {
                unordered_map<TreeNode*, bool> visited;
                dfs(it.first, count, 0, edges, distance, leaf, visited);
            }
        }

        return count / 2;
    }

private:
    void dfs(TreeNode* node, int &count, int dist, unordered_map<TreeNode*, vector<TreeNode*>> &edges, int distance, unordered_map<TreeNode*, bool> &leaf, unordered_map<TreeNode*, bool> &visited) {
        if (dist > distance) return;

        visited[node] = true;

        for (auto it : edges[node]) {
            if (!visited[it]) {
                if (leaf[it] && dist + 1 <= distance) {
                    count++;
                }
                dfs(it, count, dist + 1, edges, distance, leaf, visited);
            }
        }
        
        visited[node] = false;
    }

    void recurse(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &edges, unordered_map<TreeNode*, bool> &leaf) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            leaf[root] = true;
            return;
        }

        if (root->left != NULL) {
            recurse(root->left, edges, leaf);
            edges[root].push_back(root->left);
            edges[root->left].push_back(root);
        }

        if (root->right != NULL) {
            recurse(root->right, edges, leaf);
            edges[root].push_back(root->right);
            edges[root->right].push_back(root);
        }

        leaf[root] = false;
    }
};


