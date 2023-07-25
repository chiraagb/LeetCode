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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res ;
        if(root == NULL) return res;
        
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        bool flag = true;
        // Left to Right .. flag = true
        // Right to left .. flag = false
        
        while(!nodeQ.empty()){
            int size = nodeQ.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node = nodeQ.front();
                nodeQ.pop();
                
                int index = (flag) ? i:(size-1-i);
                
                row[index] = node->val;
                if(node->left){
                    nodeQ.push(node->left);
                    
                }
                if(node->right){
                    nodeQ.push(node->right);
                }
                
            }
            flag = !flag;
            res.push_back(row);
            
        }
        return res;
    }
};