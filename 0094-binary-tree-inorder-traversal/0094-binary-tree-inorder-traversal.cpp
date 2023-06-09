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
    // void inOrder(TreeNode* root,vector<int>&v){
    //     if(root==NULL) return;
    //     inOrder(root->left,v);
    //     v.push_back(root->val);
    //     inOrder(root->right,v);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        //Left Root Right
        // vector<int> v;
        // inOrder(root,v);
        // return v;
        
        /** Iterative InOrder **/
        vector<int> ans;
        stack<TreeNode*>st;
        
        TreeNode* node = root;
        
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        
        return ans;
        
    }
};