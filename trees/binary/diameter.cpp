class Solution {
public:
    int ans = 0;
    //O(n)
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans,lh+rh);  // CURRENT HEIGHT
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};