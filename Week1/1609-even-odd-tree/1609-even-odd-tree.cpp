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
    bool isEvenOddTree(TreeNode* root) {
        // Create a queue for nodes that need to be visted and add the root
        queue<TreeNode*> queue;
        TreeNode* current = root;
        bool even = true;
        queue.push(current);
        while(!queue.empty()){
            int prev = (even)? INT_MIN: INT_MAX;
            int size = queue.size();
            while(size > 0){
                current = queue.front();
                queue.pop();
                if(even){
                    if(current->val <= prev || current->val % 2 == 0){
                        return false;
                    }   
                }else{
                    if(current->val >= prev || current->val % 2 == 1)
                        return false;
                }
                prev = current->val;
                if(current->left){
                    queue.push(current->left);
                }
                if(current->right){
                    queue.push(current->right);
                }
                size--;
            }
            even = !even;
        }
        return true;
    }
};