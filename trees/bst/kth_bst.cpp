class Solution {
public:
    int prevorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        //LEFT SUBTREE
        if(root->left){
            int lans = kthSmallest(root->left,k);
            if(lans != -1) return lans;
        }
        //ROOT
        if(prevorder+1 == k) return root->val;
        prevorder++;
        //RIGHT SUBTREE
        if(root->right){
            int rans = kthSmallest(root->right,k);
            if(rans != -1) return rans;
        }
        return -1;
    }
};