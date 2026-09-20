class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* LLCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* RLCA = lowestCommonAncestor(root->right,p,q);
        if(LLCA && RLCA) return root;
        else if(LLCA) return LLCA;
        else return RLCA;
    }
};